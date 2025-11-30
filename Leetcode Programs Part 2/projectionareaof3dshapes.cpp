class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int grid_size=grid.size();
        int ans=0;
        for(int i=0;i<grid_size;i++){
            int bestRow=0;
            int bestCol=0;
            for(int j=0;j<grid_size;j++){
                if(grid[i][j]>0){
                    ans++;
                }
                bestRow=max(bestRow,grid[i][j]);
                bestCol=max(bestCol,grid[j][i]);
            }
            ans +=bestCol+bestRow;
        }
        return ans;
    }
};
