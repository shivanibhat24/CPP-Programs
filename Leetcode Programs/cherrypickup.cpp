class Solution {
    vector<vector<vector<int>>> dp;
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, solve(grid, 0, 0, 0));
    }
    
    int solve(vector<vector<int>> &grid, int r1, int c1, int c2){
        int r2 = r1 + c1 - c2, ans = 0, n=grid.size();
        if(r1==n || r2 == n || c1 == n || c2 == n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        
        if(r1==n-1 && c1 == n-1) return grid[n-1][n-1];
        
        if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        
        ans = grid[r1][c1];
        
        if(r2 != r1 && c2 != c1) ans += grid[r2][c2];
        
        ans += max({solve(grid, r1+1, c1, c2), 
                    solve(grid, r1, c1+1, c2),
                    solve(grid, r1+1, c1, c2+1),
                    solve(grid, r1, c1+1, c2+1)
                    
                   });
        return dp[r1][c1][c2] = ans;    
        
    }
};
