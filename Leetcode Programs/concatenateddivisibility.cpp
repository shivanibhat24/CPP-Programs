class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        ranges::sort(nums);
        int n = nums.size();
        vector<int> pow10(n);
        for (int i = 0; i < n; i++) {
            pow10[i] = pow(10, to_string(nums[i]).size());
        }
        vector<int> ans;
        vector vis(1 << n, vector<uint8_t>(k));
        auto dfs = [&](this auto&& dfs, int s, int x) -> bool {
            if (s == 0) {
                return x == 0;
            }
            if (vis[s][x]) {
                return false;
            }
            vis[s][x] = true;
            for (int i = 0; i < n; i++) {
                if (s & (1 << i) && dfs(s ^ (1 << i), (x * pow10[i] + nums[i]) % k)) {
                    ans.push_back(nums[i]);
                    return true;
                }
            }
            return false;
        };
        if (!dfs((1 << n) - 1, 0)) {
            return {};
        }
        ranges::reverse(ans); 
        return ans;
    }
};
