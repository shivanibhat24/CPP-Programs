class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, -1, 0, 1};

    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& qt, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return;
        grid[i][j] = 2;
        qt.push({i, j});
        for (int k = 0; k < 4; k++) {
            dfs(grid, i + drow[k], j + dcol[k], qt, n);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> qt;
        bool flag = false;

        // Step 1: find and mark first island using DFS
        for (int i = 0; i < n && !flag; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, qt, n);
                    flag = true;
                    break;
                }
            }
        }

        // Step 2: BFS to expand from first island to reach second
        int steps = 0;
        while (!qt.empty()) {
            int size = qt.size();
            while (size--) {
                auto [row, col] = qt.front();
                qt.pop();

                for (int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
                        if (grid[nrow][ncol] == 1) return steps; 
                        if (grid[nrow][ncol] == 0) {
                            grid[nrow][ncol] = 2;
                            qt.push({nrow, ncol});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
