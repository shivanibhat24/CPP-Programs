using int2=pair<int,int>;
vector<int2> moves={{1,0},{-1, 0},{0,1},{0,-1}};
const int mod=1e9+7;
class Solution {
public:
    int dp[51][51][51];
    int m, n;
    int f(int i, int j, int moveLeft){
        if (i<0 || i==m || j<0 || j==n) return 1;
        if (moveLeft==0) return 0;
        if (dp[i][j][moveLeft]!=-1) return dp[i][j][moveLeft];
        long long ans=0;
        for (auto [a, b]: moves){
            int r=i+a, c=j+b;
            ans=(ans+f(r, c, moveLeft-1))%mod;
        }
        return dp[i][j][moveLeft]=ans;
    }
    int findPaths(int m, int n, int maxMove, int Row, int Column) {
        this->m=m, this->n=n;
        memset(dp, -1, sizeof(dp));
        return f(Row, Column, maxMove);
    }
};
