typedef vector<vector<long long>> vv_int;
typedef vector<long long> v_int;
#define MOD 1000000007
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vv_int dp(n+1,v_int(goal+1,0));
        dp[0][0] = 1;
        for(int i = 0;i<n+1;i++){
            for(int j = 0;j<goal+1;j++){
                if(dp[i][j] == 0){
                    continue;
                }
                int nexti = i+1, nextj = j+1;
                if((nexti < (n+1)) && (nextj < (goal+1))){
                    dp[nexti][nextj] = (dp[nexti][nextj] + ((dp[i][j] * newsongs) % MOD)) % MOD;
                }
                nexti = i, nextj = j+1;
                if((nexti < (n+1)) && (nextj < (goal+1))){
                    long long newsongs = max(0,i-k);
                    dp[nexti][nextj] = (dp[nexti][nextj] + ((dp[i][j] * newsongs) % MOD)) % MOD;
                }
            }
        }
        return dp[n][goal];
    }
};
