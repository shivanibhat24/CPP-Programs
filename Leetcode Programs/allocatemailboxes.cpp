class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        const int n = houses.size();
        ranges::sort(houses);
        int d[n][n];
        int f[n][k];
        memset(d, 0, sizeof(d));
        memset(f, -1, sizeof(f));
        for(int i = n - 2; i >= 0; --i) {
            for(int j = i + 1; j < n; ++j) {
                d[i][j] = houses[j] - houses[i] + d[i + 1][j - 1];
            }
        }
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if(j >= i) return 0;
            if(j == 0)
                return d[0][i];
            int &res = f[i][j];
            if(res != -1) return res;
            res = INT_MAX / 2;
            for(int k = i; k >= j; --k) {
                res = min(res, dfs(k - 1, j - 1) + d[k][i]);
            }
            return res;
        };
        return dfs(n - 1, k - 1);
    }
};
