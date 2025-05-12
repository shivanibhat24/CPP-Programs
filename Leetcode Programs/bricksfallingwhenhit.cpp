class Solution {
public:
    int n, m;
    int h[4] = {0, 0, -1, 1}, v[4] = {-1 ,1, 0, 0};
    int dfs(int i, int j, vector<vector<int>> &grid) {
        int count = 0;
        grid[i][j] = 2;
        for(int k=0;k<4;k++) {
            int ni = i+h[k], nj = j+v[k];
            if(ni<0 || nj<0 || ni>=m || nj>=n || grid[ni][nj]!=1) {
                continue;
            }
            grid[ni][nj] = 2;
            count += 1+dfs(ni, nj, grid);
        }
        return count;
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hit) {
        m = grid.size(), n = grid[0].size();
        vector<int> res(hit.size(), 0);
        for(int i=0;i<hit.size();i++) {
            int x=hit[i][0], y=hit[i][1];
            if(grid[x][y] == 1) {
                grid[x][y] = 0;
            }
            else {
                hit[i][1] = -1;
                hit[i][0] = -1;
            }
        }
        for(int i=0; i<n; i++) {
            if(grid[0][i]) {
                dfs(0, i, grid);
            }
        }
        for(int k=hit.size()-1; k>=0; k--) {
            int i = hit[k][0], j = hit[k][1];
            if(i == -1 || j == -1) {
                res[k]=0;
                continue;
            }
            grid[i][j]=1;
            if(i == 0) {
                res[k] = dfs(i, j, grid);
                continue;
            }
            for(int p=0; p<4; p++) {
                int ni=i+h[p], nj=j+v[p];
                if(ni<0 || nj<0 || ni>=m || nj>=n || grid[ni][nj] != 2) {
                    continue;
                }
                res[k]=dfs(i, j, grid);
                break;
            }
        }
        return res;
    }
};
