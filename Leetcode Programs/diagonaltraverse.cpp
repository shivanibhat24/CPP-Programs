class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> res;
        int direct = 1, col = 0, row = 0;
        for (int i = 0; i < n * m; ++i) {
            res.push_back(mat[row][col]);
            if (direct == 1) { 
                if (col == m - 1) {
                    ++row;
                    direct = -1;
                } else if (row == 0) {
                    ++col;
                    direct = -1;
                } else {
                    --row;
                    ++col;
                }
            } else { 
                if (row == n - 1) {
                    ++col;
                    direct = 1;
                } else if (col == 0) {
                    ++row;
                    direct = 1;
                } else {
                    ++row;
                    --col;
                }
            }
        }
        return res;
    }
};
