class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
    int ans = INT_MIN;
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            int mn = INT_MAX;
            if(i == 0 && j == 0) continue;
            if(i != 0) mn = min(mn, grid[i-1][j]);
            if(j != 0) mn = min(mn, grid[i][j-1]);
            ans = max(ans, grid[i][j] - mn);
            grid[i][j] = min(grid[i][j], mn);
        }
    }
    return ans;
}
};
