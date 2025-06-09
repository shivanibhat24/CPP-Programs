const int MX = 51;
vector<int> coprime[MX];
auto init = [] {
    for (int i = 1; i < MX; i++) {
        for (int j = 1; j < MX; j++) {
            if (gcd(i, j) == 1) {
                coprime[i].push_back(j);
            }
        }
    }
    return 0;
}();
class Solution {
    vector<vector<int>> g;
    vector<int> ans;
    pair<int, int> val_depth_id[MX];
    void dfs(int x, int fa, int depth, vector<int> &nums) {
        int val = nums[x];
        int max_depth = 0;
        for (int j : coprime[val]) {
            auto [depth, id] = val_depth_id[j];
            if (depth > max_depth) {
                max_depth = depth;
                ans[x] = id;
            }
        }
        auto tmp = val_depth_id[val];
        val_depth_id[val] = {depth, x};
        for (int y : g[x]) {
            if (y != fa) {
                dfs(y, x, depth + 1, nums);
            }
        }
        val_depth_id[val] = tmp;
    }
public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();
        g.resize(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ans.resize(n, -1);
        dfs(0, -1, 1, nums);
        return ans;
    }
};
