class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& a, int s, int t) {
        int n = a.size(), m = -1;
        if(s==t) return 0;
        for (int i = 0; i < n; i++) {
            for (auto k : a[i])
                m = max(m, k);
        }
        if(s>m || t>m) return -1;
        vector<int> dp(m + 1, n + 1);
        cout<<m<<endl;
        dp[s] = 0;
        int flag = 1;
        while(flag) {
            flag=0;
            for (int i = 0; i < n; i++) {
                int res=n+1;
                for (auto k : a[i]){
                    res=min(res,dp[k]);
                }
                res++;
                for (auto k : a[i]){
                    if(res<dp[k]) {
                        dp[k]=res;
                        flag=1;
                    }
                }
            }
        }
        return dp[t]>n?-1:dp[t];
    }
};
