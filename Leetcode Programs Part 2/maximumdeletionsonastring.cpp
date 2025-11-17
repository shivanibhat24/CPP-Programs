class Solution {
public:
    int deleteString(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int maxi = 1;
            int k = i;
            for (int j = i + 1; j < n; j++) {
                if (s[j] != s[k]) {
                    k = i;
                    if (s[j] == s[k]) ++k;
                    continue;
                }
                int len1 = j - i + 1;
                int len2 = k - i + 1;
                k++;
                if (len1 % 2 != 0) continue;
                if (len2 == len1 / 2) {
                    maxi = max(maxi, 1 + dp[i + len2]);
                    k = i;
                }
            }
            dp[i] = maxi;
        }
        return dp[0];
    }
};
