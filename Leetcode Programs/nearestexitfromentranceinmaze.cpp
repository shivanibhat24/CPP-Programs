class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[entrance[0]][entrance[1]] = 1;
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto top = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int r = top.first + dir[k].first;
                    int c = top.second + dir[k].second;
                    if (r < 0 || c < 0 || r >= m || c >= n || vis[r][c] ||
                        maze[r][c] == '+')
                        continue;
                    else if (r == 0 || c == 0 || r == m - 1 || c == n - 1)
                        return ans + 1;
                    q.push({r, c});
                    vis[r][c] = 1;
                }
            }
            ans++;
        }
        return -1;
    }
};
