class Solution {
public:
int minimumVisitedCells(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size(), steps = 0;
    vector<vector<int>> max_i(m, vector<int>(n)), max_j(m, vector<int>(n));
    vector<pair<int, int>> q{{0, 0}}, q1;
    while (!q.empty()) {
        ++steps;
        for (auto [i, j] : q) {
            if (i == m - 1 && j == n - 1)
                return steps;
            for (int k = i + 1; k < m && k - i <= g[i][j]; ++k) {
                if (max_i[k][j] == 0) {
                    q1.push_back({k, j});
                    max_i[k][j] = i + g[i][j];
                }
                else
                    k = max_i[k][j];
            }
            for (int k = j + 1; k < n && k - j <= g[i][j]; ++k) {
                if (max_j[i][k] == 0) {
                    q1.push_back({i, k});
                    max_j[i][k] = j + g[i][j];
                }
                else
                    k = max_j[i][k];
            }
        }
        swap(q, q1);
        q1.clear();
    }
    return -1;
}
};
