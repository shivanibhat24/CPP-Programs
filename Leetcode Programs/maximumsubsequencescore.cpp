#define NO_SAN __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define INL_ATTR noexcept INL NO_SAN HOT
#define OUTL_ATTR noexcept NO_SAN HOT

#pragma clang diagnostic ignored "-Wshift-op-parentheses"

template <class C, uint SIZE>
class static_sparse_bit_multiset_3 {
private:
    static constexpr uint BSIZE = SIZE + 63 >> 6, MSIZE = BSIZE + 63 >> 6;

    C freqs[SIZE];
    uint64_t bottom[BSIZE], middle[MSIZE];
    uint top = 0, count = 0;

public:
    void insert(const uint v) INL_ATTR {
        freqs[v]++;
        const uint b = v >> 6, m = b >> 6;
        bottom[b] |= 1ull << (v & 63);
        middle[m] |= 1ull << (b & 63);
        top |= 1u << (m & 63);
        count++;
    }

    void erase(const uint v) INL_ATTR {
        const C f = --freqs[v];
        const uint b = v >> 6, m = b >> 6;
        const uint64_t botq = bottom[b] &= ~(uint64_t(!f) << (v & 63)),
                       midq = middle[m] &= ~(uint64_t(!botq) << (b & 63));
        top &= ~(!midq << (m & 63));
        count--;
    }

    uint pop_front() INL_ATTR {
        const uint8_t m = countr_zero(top);
        uint64_t midq = middle[m];
        const uint8_t bi = countr_zero(midq);
        const uint b = (m << 6) + bi;
        uint64_t botq = bottom[b];
        const uint8_t vi = countr_zero(botq);
        const uint v = (b << 6) + vi;
        const C f = --freqs[v];
        bottom[b] = botq &= ~(uint64_t(!f) << vi);
        middle[m] = midq &= ~(uint64_t(!botq) << bi);
        top &= ~(!midq << m);
        count--;
        return v;
    }

    uint pop_back() INL_ATTR {
        const uint8_t m = 31 - countl_zero(top);
        uint64_t midq = middle[m];
        const uint8_t bi = 63 - countl_zero(midq);
        const uint b = (m << 6) + bi;
        uint64_t botq = bottom[b];
        const uint8_t vi = 63 - countl_zero(botq);
        const uint v = (b << 6) + vi;
        const C f = --freqs[v];
        bottom[b] = botq &= ~(uint64_t(!f) << vi);
        middle[m] = midq &= ~(uint64_t(!botq) << bi);
        top &= ~(!midq << m);
        count--;
        return v;
    }

    uint size() const INL_ATTR {
        return count;
    }

    void clear() INL_ATTR {
        for (uint t = top; t; ) {
            const uint8_t m = countr_zero(t);
            for (uint64_t midq = middle[m]; midq; ) {
                const uint8_t bi = countr_zero(midq);
                const uint b = (m << 6) + bi;
                for (uint64_t botq = bottom[b]; botq; ) {
                    const uint vi = countr_zero(botq);
                    freqs[(b << 6) + vi] = 0;
                    botq ^= 1ull << vi;
                }
                bottom[b] = 0;
                midq ^= 1ull << bi;
            }
            middle[m] = 0;
            t ^= 1u << m;
        }
        top = count = 0;
    }
};

template <class T, uint CAP, T NONE = T(-1)>
struct static_allocator {
    struct item_t {
        T data;
        uint next;
    };

    item_t items[CAP];
    uint used, freehead;

    static_allocator() INL_ATTR: used(0), freehead(NONE) {}

    uint alloc() INL_ATTR {
        uint i;
        if (freehead != NONE) {
            i = freehead;
            freehead = items[freehead].next;
        } else {
            i = used++;
            // assert(used <= MAXN);
        }
        items[i].next = NONE;
        return i;
    }

    void free(const uint i) INL_ATTR {
        items[i].next = freehead;
        freehead = i;
    }

    void clear() INL_ATTR {
        used = 0;
        freehead = NONE;
    }
};

template <class K, class T, uint CAP, T NONE = T(-1)>
class part_queue {
private:
    static static_allocator<T, CAP, NONE> allocator;

    static void _push(uint &i, const T v) INL_ATTR {
        const uint j = allocator.alloc();
        allocator.items[j].data = v;
        allocator.items[j].next = i;
        i = j;
    }

    static T _pop(uint &i) INL_ATTR {
        const uint j = i;
        const T v = allocator.items[j].data;
        i = allocator.items[j].next;
        allocator.free(j);
        return v;
    }

    uint queues[CAP], count;

public:
    part_queue() INL_ATTR: count(0) {
        fill(queues, queues + CAP, NONE);
    }

    void push(const K k, const T v) INL_ATTR {
        _push(queues[k], v);
        count++;
    }

    T pop(const K k) INL_ATTR {
        count--;
        return _pop(queues[k]);
    }

    uint size() const INL_ATTR {
        return count;
    }

    bool empty() const INL_ATTR {
        return !count;
    }

    bool empty(const K k) const INL_ATTR {
        return queues[k] == NONE;
    }

    void clear(const uint mink, const uint maxk) INL_ATTR {
        // fill(queues + mink, queues + (maxk + 1u), NONE);
        allocator.clear();
    }
};

template <class K, class T, uint CAP, T NONE>
static_allocator<T, CAP, NONE> part_queue<K, T, CAP, NONE>::allocator;

class Solution {
private:
    static constexpr uint MAXN = 100'000;

    typedef static_sparse_bit_multiset_3<uint16_t, MAXN+1u> multiset_t;
    typedef part_queue<uint, uint, MAXN+1u> partq_t;

    static multiset_t prio;
    static partq_t part;

public:
    static long long maxScore(vector<int>& vel, vector<int>& eff, const uint k) OUTL_ATTR {
        const uint n = vel.size();
        uint maxe = 0;
        for (uint i = 0; i < n; i++) {
            const uint e = eff[i];
            part.push(e, vel[i]);
            maxe = max(e, maxe);
        }
        uint64_t sum = 0, maxprod = 0, e = maxe + 1u;
        while (e--) {
            while (!part.empty(e)) {
                const uint v = part.pop(e);
                prio.insert(v);
                sum += v;
                if (prio.size() > k)
                    sum -= prio.pop_front();
                if (prio.size() == k)
                    maxprod = max(sum * e, maxprod);
            }
        }
        prio.clear();
        part.clear(0, e + 1u); // todo do we even need this?
        return maxprod;
    }
};

Solution::multiset_t Solution::prio;
Solution::partq_t Solution::part;

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
