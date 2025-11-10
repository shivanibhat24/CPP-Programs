class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
         const int MOD = 1e9 + 7;
        long long dp0 = 0, dp1 = 0;
        bool hasZero = false;

        for (char ch : binary) {
            if (ch == '1') {
                dp1 = (dp0 + dp1 + 1) % MOD;  // start new subseq + extend all
            } else {
                dp0 = (dp0 + dp1) % MOD;      // extend subsequences ending with '1'
                hasZero = true;
            }
        }

        return (dp0 + dp1 + (hasZero ? 1 : 0)) % MOD;
    }
};
