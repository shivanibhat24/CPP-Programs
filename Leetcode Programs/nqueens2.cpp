class Solution {
public:
    void solve(int col, int &ans, vector<int> &lrow, vector<int> &ud, vector<int> &ld, int n) {
        if (col == n) {
            ans++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (lrow[row] == -1 && ud[row - col + n - 1] == -1 && ld[row + col] == -1) {
                lrow[row] = 1;
                ud[row - col + n - 1] = 1;
                ld[row + col] = 1;
                solve(col + 1, ans, lrow, ud, ld, n);
                lrow[row] = -1;
                ud[row - col + n - 1] = -1;
                ld[row + col] = -1;
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> lrow(n, -1), ud(2 * n, -1), ld(2 * n, -1);
        solve(0, ans, lrow, ud, ld, n);
        return ans;
    }
};
