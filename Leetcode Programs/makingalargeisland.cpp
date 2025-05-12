class Solution {
    int d[5] = {1, 0, -1, 0, 1}; 
    int n;
    int dfs(int row, int col, int id, vector<vector<int>>& grid) {
        grid[row][col] = id; 
        int cnt = 1;
        for (int i = 0; i < 4; i++) { 
            int nr = row + d[i];
            int nc = col + d[i + 1];
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1)
                cnt += dfs(nr, nc, id, grid);
        }
        return cnt; 
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(); 
        vector<int> key; 
        int id = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    key.push_back(dfs(i, j, id++, grid));
            }
        }
        if (key.empty()) return 1;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int cnt = 1;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + d[k];
                        int nc = j + d[k + 1];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] != 0 && key[grid[nr][nc] - 2] > 0)
                            cnt += key[grid[nr][nc] - 2], key[grid[nr][nc] - 2] *= -1;
                    }
                    for (int k = 0; k < 4; k++) {
                        int nr = i + d[k];
                        int nc = j + d[k + 1];

                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] != 0 && key[grid[nr][nc] - 2] < 0)
                            key[grid[nr][nc] - 2] *= -1; 
                    }
                    ans = max(ans, cnt); 
                }
            }
        }
        return ans == 1 ? n * n : ans; 
    }
};
