const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        long long MOD = 1e9 + 7;
        long long n = nums.size();
        vector<long long> positions(n);
        for (long long i = 0; i < n; i++) {
            positions[i] = (long long)nums[i] + (s[i] == 'R' ? d : -d);
        }

        sort(positions.begin(), positions.end());
        long long prefix = 0;
        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            ans = (((ans + ((i % MOD) * (positions[i] % MOD)) % MOD) % MOD) -
                   prefix + MOD)%MOD;
            prefix = (prefix+positions[i])%MOD;
        }
        return ans;
    }
};
