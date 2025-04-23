#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define INL_ATTR noexcept INL HOT
#define OUTL_ATTR noexcept HOT
#define LAM_ATTR INL HOT noexcept

template <class K, class T, size_t max_size, unsigned char bucket_bits>
class static_flat_hash_map {
public:
    typedef pair<K, T> value_type;
    typedef value_type *iterator;

    static constexpr K ZERO_VAL = __builtin_constant_p((K)INT_MIN) ? (K)INT_MIN : (K)INT_MIN;
    static constexpr K RM_VAL = __builtin_constant_p((K)0xdeadbeefdeadbeefull);

    static bool equal(K km, K ku) INL_ATTR {
        return km && (km == ZERO_VAL ? 0 : km) == ku;
    }

    static bool equal_or_free(K km, K ku) INL_ATTR {
        return !km || (km == ZERO_VAL ? 0 : km) == ku;
    }

    static constexpr size_t min_cap = 16u;

    static constexpr size_t getcap(size_t size) INL_ATTR {
        return size <= min_cap ? min_cap : 1ull << (64u - __builtin_clzll(size - 1u));
    }

    static constexpr size_t cap = getcap(max_size);

private:
    value_type storage[cap];
    size_t limit;

    static size_t hash(K k) INL_ATTR {
        return size_t(k) ^ (size_t(k) >> 9);
    }

    value_type *locate(K k) OUTL_ATTR {
        const size_t h = (hash(k) << bucket_bits) & (limit - 1);
        size_t i = h;
        while (i < limit && !equal_or_free(storage[i].first, k)) i++;
        if (i >= limit) {
            i = 0;
            while (i < h && !equal_or_free(storage[i].first, k)) i++;
        }
        return storage + i;
    }

    value_type *locate_ins(K k) OUTL_ATTR {
        const size_t h = (hash(k) << bucket_bits) & (limit - 1);
        size_t i = h;
        size_t f = h;
        while (i < limit && !equal_or_free(storage[i].first, k)) {
            if (f == h && storage[i].first == RM_VAL) f = i;
            i++;
        }
        if (i >= limit) i = 0;
        while (i < h && !equal_or_free(storage[i].first, k)) {
            if (f == h && storage[i].first == RM_VAL) f = i;
            i++;
        }
        return storage + (f == h ? i : f);
    }

public:

    static_flat_hash_map() INL_ATTR: limit(cap) {}

    iterator find(K k) INL_ATTR {
        value_type *p = locate(k);
        return p;
    }

    iterator insert(iterator p, const value_type &v) INL_ATTR {
        p->first = v.first ? v.first : ZERO_VAL;
        p->second = v.second;
        return p;
    }

    iterator insert(const value_type &v) INL_ATTR {
        auto p = locate_ins(v.first);
        return insert(p, v);
    }

    T &operator[](const K k) INL_ATTR {
        auto p = locate_ins(k);
        if (!equal(p->first, k))
            insert(p, pair(k, T()));
        return p->second;
    }

    bool remove(K k) INL_ATTR {
        auto p = locate(k);
        if (!equal(p->first, k)) return false;
        auto n = p + 1 < storage + limit ? p + 1 : storage;
        p->first = n->first ? RM_VAL : 0;
        return true;
    }

    void clear() INL_ATTR {
        fill(storage, storage + limit, pair(0, 0));
    }

    void setlimit(const size_t l) INL_ATTR {
        limit = getcap(l);
    }
};

class Solution {
private:
    static constexpr unsigned MAXN = 100000u, MAXQ = MAXN * 3u / 4u;
    typedef static_flat_hash_map<int, unsigned, MAXN, 1> map_t;
    static int lower[MAXQ + 1u], upper[MAXQ];
    static map_t deleted;

    static int64_t pack(unsigned lb, unsigned ub, const int bal) INL_ATTR {
        return lb + (ub << 17) + ((int64_t)bal << 34);
    }

    static unsigned getlb(const int64_t p) INL_ATTR {
        return p & ((1u << 17) - 1u);
    }

    static unsigned getub(const int64_t p) INL_ATTR {
        return (p >> 17) & ((1u << 17) - 1u);
    }

    static int getbal(const int64_t p) INL_ATTR {
        return p >> 34;
    }

    template <class Op>
    static int64_t commit_del(int *heap, unsigned b, int bal, const int inc, Op cmp) OUTL_ATTR {
        map_t::iterator it = nullptr;
        while (b && deleted.equal((it = deleted.find(*heap))->first, *heap) && it->second) {
            deleted.remove(*heap);
            pop_heap(heap, heap + b, cmp);
            b--;
            bal += inc;
            it->second--;
        }
        return pack(b, 0, bal);
    }

    static int64_t add(const int num, unsigned lb, unsigned ub, int bal) OUTL_ATTR {
        if (num >= *upper) {
            int moved = lb ? *lower : num;
            if (num < moved) {
                lower[lb] = num;
                push_heap(lower, lower + lb + 1u);
                pop_heap(lower, lower + lb + 1u);
            } else if (num != moved) {
                moved = num;
            }
            upper[ub++] = moved;
            push_heap(upper, upper + ub, greater());
            while ((int)lb + 1 < (int)ub + bal) {
                const auto it = deleted.find(*upper);
                if (deleted.equal(it->first, *upper) && it->second) {
                    bal--;
                    it->second--;
                } else {
                    lower[lb++] = *upper;
                    push_heap(lower, lower + lb);
                }
                pop_heap(upper, upper + ub, greater());
                ub--;
                const int64_t p = commit_del(upper, ub, bal, 1, greater());
                ub = getlb(p); // always packed in low-order slot
                bal = getbal(p);
            }
        } else {
            int moved = *upper;
            if (num > moved) {
                upper[ub] = num;
                push_heap(upper, upper + ub + 1u, greater());
                pop_heap(upper, upper + ub + 1u, greater());
            } else if (num != moved) {
                moved = num;
            }
            lower[lb++] = moved;
            push_heap(lower, lower + lb);
            while ((int)lb > (int)ub + bal) {
                const auto it = deleted.find(*lower);
                if (deleted.equal(it->first, *lower) && it->second) {
                    bal++;
                    it->second--;
                } else {
                    upper[ub++] = *lower;
                    push_heap(upper, upper + ub, greater());
                }
                pop_heap(lower, lower + lb);
                lb--;
                const int64_t p = commit_del(lower, lb, bal, -1, less());
                lb = getlb(p);
                bal = getbal(p);
            }
        }
        return pack(lb, ub, bal);
    }

    static int64_t replace(const int old, const int num, unsigned lb, unsigned ub, int bal) OUTL_ATTR {
        if (old == num) return pack(lb, ub, bal);
        if (ub && old == *upper) {
            pop_heap(upper, upper + ub, greater());
            ub--;
            const int64_t p = commit_del(upper, ub, bal, 1, greater());
            ub = getlb(p); // always packed in low-order slot
            bal = getbal(p);
        } else if (lb && old == *lower) {
            pop_heap(lower, lower + lb);
            lb--;
            const int64_t p = commit_del(lower, lb, bal, -1, less());
            lb = getlb(p);
            bal = getbal(p);
        } else {
            bal += ub && old >= *upper ? -1 : 1;
            deleted[old]++;
        }
        return add(num, lb, ub, bal);
    }

    static double median(const unsigned lb, const unsigned ub, const int bal, const bool odd) INL_ATTR {
        return odd || (lb && ub && *lower == *upper) ? *upper : ((int64_t)*lower + *upper) / 2.;
    }

public:
    static vector<double> medianSlidingWindow(const vector<int>& nums, const unsigned k) OUTL_ATTR {
        const unsigned n = nums.size();
        if (n == 1) return vector<double>(1, nums.front());
        vector<double> r;
        r.reserve(n - k + 1u);
        deleted.setlimit((max(n, k + 1u) - k - 1u) * 2u);
        unsigned lb = 0, ub = 0, i = 0;
        int bal = 0;
        for ( ; i < k; i++) {
            const int64_t p = add(nums[i], lb, ub, bal);
            lb = getlb(p);
            ub = getub(p);
            bal = getbal(p);
        }
        r.push_back(median(lb, ub, bal, k & 1u));
        for ( ; i < n; i++) {
            const int64_t p = replace(nums[i-k], nums[i], lb, ub, bal);
            lb = getlb(p);
            ub = getub(p);
            bal = getbal(p);
            r.push_back(median(lb, ub, bal, k & 1u));
        }
        deleted.clear();
        return r;
    }
};

int Solution::lower[MAXQ + 1u], Solution::upper[MAXQ];
Solution::map_t Solution::deleted;
 
auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 1337;
}();
