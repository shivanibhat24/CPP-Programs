class Solution {
public:
    const int MOD= 1e9+7;
    int sumOfPower(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        long long ans = 0, prefixSum = 0;

        for (int num : nums) {
            long long square = 1LL * num * num % MOD;
            long long contrib = (square * ((num + prefixSum) % MOD)) % MOD;
            ans = (ans + contrib) % MOD;

            prefixSum = (2 * prefixSum + num) % MOD;
        }

        return ans;
    }
};
