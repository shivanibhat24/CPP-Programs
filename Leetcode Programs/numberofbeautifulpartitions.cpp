class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        int n=s.size();
        bool prime[127];
        for (int i='0';i<='9';i++) prime[i]=0;
        prime['2']=prime['3']=prime['5']=prime['7']=1;        
        if (prime[s[n-1]] || !prime[s[0]]) return 0;
        if (k==1) return 1;
        long long t[n+1][k+1],ret=0;
        for (int i=0;i<=k;i++) t[n][i]=0;
        for (int i=n-1;i>=0;i--){
            for (int j=0;j<=k;j++) t[i][j]=t[i+1][j];
            if (i+minLength<=n && prime[s[i]] && (i==0 || !prime[s[i-1]])){
                t[i][1]++;
                t[i][1]%=1000000007;
                for (int j=2;j<=k;j++) {
                    t[i][j]+=t[i+minLength][j-1];
                    t[i][j]%=1000000007;
                    if (j==k && i==0) {
                        ret+=t[i+minLength][j-1];
                        ret%=1000000007;
                    }
                }
            }
        }
        return ret;
    }
};
