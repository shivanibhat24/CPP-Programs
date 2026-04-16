class Solution {
public:
    vector<vector<int>> adj;
    vector<int> nums;
    int target;
    int formed;

    int dfs(int node, int parent) {
        int sum = nums[node];

        for (int nei : adj[node]) {
            if (nei == parent) continue;

            int child = dfs(nei, node);
            if (child == -1) return -1;

            sum += child;
        }
        if (sum == target) {
            formed++;
            return 0;
        }
        if (sum > target) return -1;

        return sum;
    }

    int componentValue(vector<int>& nums_, vector<vector<int>>& edges) {
        nums = nums_;
        int n = nums.size();

        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int total = 0;
        for (int x : nums) total += x;
        for (int k = n; k >= 1; k--) {
            if (total % k != 0) continue;

            target = total / k;
            formed = 0;

            if (dfs(0, -1) == 0 && formed == k) {
                return k - 1; 
            }
        }

        return 0;
    }
};
