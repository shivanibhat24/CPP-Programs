class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> ret(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    ret[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = p.first + dirs[i];
                int y = p.second + dirs[i + 1];
                if (x >= 0 && x < rows && y >= 0 && y < cols && ret[x][y] == -1) {
                    ret[x][y] = ret[p.first][p.second] + 1;
                    q.emplace(x, y);
                }
            }
        }
        return ret;
    }
};
