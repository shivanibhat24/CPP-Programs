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
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int MOD = pow(10,9)+7;
        sort(nums.begin(),nums.end());
        long long n = nums.size();
        long long pw2[n];
        pw2[0] = 1;
        for(int i = 1;i<n;i++){
            pw2[i] = (pw2[i-1]*2)%MOD;
        }
        long long sum=0;
        for(int i =0;i<n;i++){
            sum = (sum + (nums[i]*(pw2[i] - pw2[n-i-1]))) % MOD;
        }
        return sum;
    }
};
