class Solution {
public:
    int dp[11][2];
    int solve(int idx, bool isBound, vector<string>& digits, string& num){
        if(idx >= num.size()) return 1;
        if(dp[idx][isBound] != -1) return dp[idx][isBound];
        int ans = 0;
        for(auto &p : digits){
            char digit = p[0];
            if(digit < num[idx]){
                ans += (solve(idx+1, false, digits, num));
            }
            else if(digit > num[idx] && isBound == false){
                ans += (solve(idx+1, false, digits, num));
            }
            else if(digit == num[idx]){
                ans += (solve(idx+1, isBound, digits, num));
            }
        }
        return dp[idx][isBound] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp, -1, sizeof(dp));
        string num = to_string(n);
        int ans = 0, sz = num.size(), m = digits.size(), prod = 1;
        for(int i = 1; i <= sz-1; i++){
            prod *= m;
            ans += prod;
        }
        return ans + solve(0, true, digits, num);
    }
};
