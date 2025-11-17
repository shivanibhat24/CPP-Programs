class Solution {
public:
    int distinctSequences(int n) {
        if(n == 1) return 6;
        const int MOD = 1e9+7;
        int dp[6][6], newdp[6][6], g[7][7];
        memset(dp, 0, sizeof(dp));
        memset(newdp, 0, sizeof(newdp));      
        for(int a=1;a<=6;a++){
            for(int b=1;b<=6;b++){
                g[a][b] = gcd(a, b);
                if(g[a][b] !=1 || a==b) continue;
                dp[a-1][b-1] = 1;
            }
        }
        for(int i=3;i<=n;i++){
            for(int a=1;a<=6;a++){
                for(int b=1;b<=6;b++){
                    if(g[a][b] != 1 || a==b) continue;
                    for(int c=1;c<=6;c++){
                        if(a == c) continue;
                        newdp[a-1][b-1] = (newdp[a-1][b-1] + dp[b-1][c-1]) % MOD;
                    }
                }
            }
            swap(dp, newdp);
            memset(newdp, 0, sizeof(newdp));
        }
        int res = 0;
        for(int a=0;a<6;a++) for(int b=0;b<6;b++) res = (res + dp[a][b]) % MOD;
        return res;
    }
};
