class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        bool vis[m][n];
        bool wall[m][n];
        bool guard[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                vis[i][j] = false;
                wall[i][j] = false;
                guard[i][j] = false;
            }

        
        for (const auto & w : walls)
        {
            wall[w[0]][w[1]] = true;
            vis[w[0]][w[1]] = true;
        }

        for (const auto & g : guards)
        {
            guard[g[0]][g[1]] = true;
            vis[g[0]][g[1]] = true;
        }

        for (const auto & g : guards)
        {
            int x = g[0];
            int y = g[1];
            for (int i = x + 1; i < m && !wall[i][y] && !guard[i][y]; i++) vis[i][y] = true;
            for (int i = x - 1; i >= 0 && !wall[i][y] && !guard[i][y]; i--) vis[i][y] = true;
            for (int i = y + 1; i < n && !wall[x][i] && !guard[x][i]; i++) vis[x][i] = true;
            for (int i = y - 1; i >= 0 && !wall[x][i] && !guard[x][i]; i--) vis[x][i] = true;
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans += vis[i][j] == false;
        return ans;
    }
};
