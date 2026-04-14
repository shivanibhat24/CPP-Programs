#include <vector>
#include <cstring>
using namespace std;
static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
    int rows, cols;
    int dp[1000][1000];
    const int MOD = 1e9 + 7;
    int solve(int r, int c, const vector<vector<int>>& grid) {
        if (dp[r][c] != 0) return dp[r][c];
        int res = 1;
        int val = grid[r][c];
        if (r > 0 && grid[r-1][c] > val) res = (res + solve(r-1, c, grid)) % MOD; 
        if (r < rows - 1 && grid[r+1][c] > val) res = (res + solve(r+1, c, grid)) % MOD;
        if (c > 0 && grid[r][c-1] > val) res = (res + solve(r, c-1, grid)) % MOD;
        if (c < cols - 1 && grid[r][c+1] > val) res = (res + solve(r, c+1, grid)) % MOD;

        return dp[r][c] = res;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        for(int i = 0; i < rows; ++i) {
            memset(dp[i], 0, cols * sizeof(int));
        }
        int total = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                total = (total + solve(i, j, grid)) % MOD;
            }
        }
        return total;
    }
};
