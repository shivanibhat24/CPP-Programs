class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        auto n = grid.size();
        vector<vector<size_t>> v(2, vector<size_t>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                auto h1 = v[0][i];
                v[0][i] ^= hash<int>()(grid[i][j]) + 0x9e3779b9 + (h1 << 6) +
                           (h1 >> 2);
                auto h2 = v[1][i];
                v[1][i] ^= hash<int>()(grid[j][i]) + 0x9e3779b9 + (h2 << 6) +
                           (h2 >> 2);;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += v[0][i] == v[1][j];
            }
        }
        return res;
    }
};
