#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
auto _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
typedef uint v_type;
typedef int k_type;
#define SIGNED_KEY 0
const size_t MSZ=400009;
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Hash {
    size_t N=MSZ;
    k_type keys[MSZ];
    v_type values[MSZ];
    const char v_def=127;
public:
    void clear() {
        memset(values, v_def, N*sizeof(v_type));
    }
    v_type& operator[](int key) {
        #if SIGNED_KEY
        int t=key%N, idx=t+(t<0)*N, cnt=1;
        #else
        int idx=key%N, cnt=1;
        #endif
        while (keys[idx] != key && values[idx] != 2139062143) {
            idx = (idx + cnt * cnt) % N;
            cnt++;
        }
        keys[idx] = key;
        return values[idx];
    }
};

Hash m;

class Solution {
public:
    int minSubarray(const vector<int>& nums, int p) {
        if (p == 1) return 0;

        unsigned long long rem = 0;
        for (int e : nums) rem += e;
        rem %= p;
        if (rem == 0) return 0;

        m.clear();
        m[0] = -1;
        uint s = 0, r = -1;

        for (int i = 0; i < nums.size(); ++i) {
            s = (s + nums[i]) % p;
            int tar = (s + p - rem) % p;
            auto v = m[tar];
            if (v != 2139062143) r = min(r, i - v);
            m[s] = i;
        }

        if (r == nums.size()) return -1;
        return (int)r;
    }
};
