class Solution {
    const int INF = 1000000000;
    vector<int> dirs = {0, 1, 0, -1, 0};
    bool pathExistsWithoutFire(const vector<vector<int>>& grid, int i, int j, int n, int m,
                               vector<vector<int>>& visited, int token) {
        if (i == n - 1 && j == m - 1) return true;
        visited[i][j] = token;
        for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d];
            int nj = j + dirs[d + 1];

            if (ni >= 0 && nj >= 0 && ni < n && nj < m && visited[ni][nj] != token && grid[ni][nj] == INF) {
                if (pathExistsWithoutFire(grid, ni, nj, n, m, visited, token)) return true;
            }
        }
        return false;
    }
    bool canReachWithWaitTime(const vector<vector<int>>& grid, int i, int j, int n, int m,
                              vector<vector<int>>& visited, int token, int time) {
        if (i == n - 1 && j == m - 1) return true;
        visited[i][j] = token;
        for (int d = 0; d < 4; ++d) {
            int ni = i + dirs[d];
            int nj = j + dirs[d + 1];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && visited[ni][nj] != token) {
                if ((ni == n - 1 && nj == m - 1 && grid[ni][nj] > time) || grid[ni][nj] > time + 1) {
                    if (canReachWithWaitTime(grid, ni, nj, n, m, visited, token, time + 1)) return true;
                }
            }
        }
        return false;
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> fireGrid(n, vector<int>(m));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    fireGrid[i][j] = 0;
                    q.push(make_pair(i, j));
                } else if (grid[i][j] == 2) {
                    fireGrid[i][j] = -1;
                } else {
                    fireGrid[i][j] = INF;
                }
            }
        }
        int maxFireTime = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dirs[d];
                    int nj = j + dirs[d + 1];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < m && fireGrid[ni][nj] == INF) {
                        fireGrid[ni][nj] = fireGrid[i][j] + 1;
                        q.push(make_pair(ni, nj));
                        maxFireTime = max(maxFireTime, fireGrid[ni][nj]);
                    }
                }
            }
        }
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int token = 1;
        if (fireGrid[0][0] == INF && pathExistsWithoutFire(fireGrid, 0, 0, n, m, visited, token)) {
            return INF;
        }
        int left = 0, right = maxFireTime;
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            ++token;
            if (canReachWithWaitTime(fireGrid, 0, 0, n, m, visited, token, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
