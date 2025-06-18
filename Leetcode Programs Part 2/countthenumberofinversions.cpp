int mod = int(1e9) + 7;
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& r) {
        sort(r.begin(), r.end());
        int k = r.back()[1];
        vector<long long> dp(k+1);
        dp[0] = 1;
        for(int i=1;i<r.size();i++) if(r[i-1][1] > r[i][1]) return 0; 
        int pre = 0;
        for(int i=0;i<r.size();i++){
            int e = r[i][0], c = r[i][1];
            // appending element with array size from pre to end_i
            for(int l=pre;l <= e;l++){
                vector<long long> ndp(k+1);
                long long su = 0;
                // windowing for appending element to array with length = l
                for(int m=0;m <= k;m++){ 
                    su += dp[m];
                    if(m >= l + 1) su -= dp[m-l-1];
                    su %= mod;
                    if(su < 0) su += mod;
                    ndp[m] = su;
                }
                dp = std::move(ndp);
            }
            for(int i=0;i<=k;i++) if(i != c) dp[i] = 0; 
            pre = e + 1;            
        }
        long long ans = 0;
        for(int i=0;i<=k;i++) ans += dp[i];
        return ans;
        
    }
};
