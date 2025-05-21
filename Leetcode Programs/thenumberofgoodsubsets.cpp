class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
        int n = primes.size();        
        vector<int> freq(31);
        for (int num : nums) freq[num]++;        
        unordered_map<int, int> validMask;
        for (int i = 2; i <= 30; ++i) {
            int mask = 0, x = i;
            bool isValid = true;
            for (int j = 0; j < n; ++j) {
                int p = primes[j];
                int count = 0;
                while (x % p == 0) {
                    x /= p;
                    count++;
                }
                if (count > 1) {
                    isValid = false;
                    break;
                }
                if (count == 1) mask |= (1 << j);
            }
            if (isValid) validMask[i] = mask;
        }
        vector<int> dp(1 << n);
        dp[0] = 1;
        for (int i = 2; i <= 30; ++i) {
            if (freq[i] == 0 || validMask.find(i) == validMask.end()) continue;
            int currMask = validMask[i];
            for (int mask = (1 << n) - 1; mask >= 0; --mask) {
                if ((mask & currMask) == 0) {
                    dp[mask | currMask] = (dp[mask | currMask] + (long long)dp[mask] * freq[i]) % MOD;
                }
            }
        }
        long long result = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            result = (result + dp[mask]) % MOD;
        }
        int ones = freq[1];
        long long pow2 = 1;
        while (ones--) pow2 = (pow2 * 2) % MOD;
        return (result * pow2) % MOD;
    }
};
