class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(row == m) return col;
        int nextCol = col + grid[row][col];
        int curr = grid[row][col];
        if(nextCol < 0 || nextCol >= n || grid[row][nextCol] != curr) return -1;
        return dfs(row+1, nextCol, grid);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for(int j=0; j<n; j++){
            ans[j] = dfs(0, j, grid);
        }
        return ans;
    }
};
