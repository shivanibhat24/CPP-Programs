class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m = targetGrid.size(), n = targetGrid[0].size();
        vector<int> minR(61, m), minC(61, n), maxR(61, -1), maxC(61, -1);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int c = targetGrid[i][j];
                minR[c] = min(minR[c], i);
                maxR[c] = max(maxR[c], i);
                minC[c] = min(minC[c], j);
                maxC[c] = max(maxC[c], j);
            }
        vector<vector<int>> grid = targetGrid;
        bool changed = true;
        while (changed) {
            changed = false;
            for (int c = 1; c <= 60; ++c) {
                if (minR[c] == m) continue;
                bool canErase = true;
                for (int i = minR[c]; i <= maxR[c] && canErase; ++i)
                    for (int j = minC[c]; j <= maxC[c] && canErase; ++j)
                        if (grid[i][j] != 0 && grid[i][j] != c) canErase = false;
                if (canErase) {
                    for (int i = minR[c]; i <= maxR[c]; ++i)
                        for (int j = minC[c]; j <= maxC[c]; ++j)
                            if (grid[i][j] == c) grid[i][j] = 0;
                    minR[c] = m;
                    changed = true;
                }
            }
        }
        for (auto& row : grid)
            for (int val : row)
                if (val != 0) return false;
        return true;
    }
};
