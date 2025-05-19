class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {        
        int n = grid.size();
        int m = grid[0].size();
        int maxCount = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int count = 0;
                if(grid[i][j] > 0){
                    dfs(i,j,grid,count);
                }
                maxCount = max(count, maxCount);
            }
        }
        return maxCount;
    }
    void dfs(int r, int c, vector<vector<int>> & grid, int & count){
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0 || grid[r][c] == -1){
            return;
        }
        count += grid[r][c];
        grid[r][c] = -1;
        dfs(r+1,c,grid,count);
        dfs(r-1,c,grid,count);
        dfs(r,c+1,grid,count);
        dfs(r,c-1,grid,count);
    }
};
