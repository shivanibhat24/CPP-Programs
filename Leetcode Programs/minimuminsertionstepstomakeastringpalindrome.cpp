class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> dp_low(n, 0), dp(n, 0);
        for(int i=n-1; i>=0; i--){
            dp[i] = 1;
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j]) dp[j] = dp_low[j-1]+2;
                else dp[j] = max(dp[j-1], dp[j]);
            }
            dp_low = dp;
        }
        return n-dp[n-1];
    }
};
