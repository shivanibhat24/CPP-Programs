class Solution {
    //vector<vector<int>> dirs = {{0,1}, {1,0}};
    long long dp1[16][16];
    long long dp2[16][16];
    long long M = 1e9+7;
    int rows, cols;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        dp1[0][0] = grid[0][0];
        dp2[0][0] = grid[0][0];

        for (int r = 1; r < rows; r++) {
            dp1[r][0] = dp1[r-1][0] * grid[r][0];
            dp2[r][0] = dp2[r-1][0] * grid[r][0];
        }
        for (int c = 1; c < cols; c++) {
            dp1[0][c] = dp1[0][c-1] * grid[0][c];
            dp2[0][c] = dp2[0][c-1] * grid[0][c];
        }

        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {

                dp1[r][c] = max( max(dp1[r-1][c]*grid[r][c], dp1[r][c-1]*grid[r][c]),
                                 max(dp2[r-1][c]*grid[r][c], dp2[r][c-1]*grid[r][c]) );
                dp2[r][c] = min( min(dp1[r-1][c]*grid[r][c], dp1[r][c-1]*grid[r][c]),
                                 min(dp2[r-1][c]*grid[r][c], dp2[r][c-1]*grid[r][c]) ); 
            }
        }

        int ans = max(dp1[rows-1][cols-1], dp2[rows-1][cols-1]) % M;
        
        return (ans < 0) ? -1 : ans;
    }
};
