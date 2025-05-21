class Solution {
public:
    int tot, n;
    vector<int> used;
    bool makesquare(vector<int>& nums) {
        n = nums.size();
        used.resize(n);
        sort(nums.begin(), nums.end(), [](int &a, int &b){return a > b;});
        for (auto x: nums) tot += x;
        if (tot % 4) return false;
        tot /= 4;
        return dfs(nums, tot, 0, 0, 0);
    }
    bool dfs(vector<int>& nums, int tot, int curr, int u, int k) {
        if (k == 3) return true;
        if (curr == tot) return dfs(nums, tot, 0, 0, k + 1);
        if (u == n) return false;
        for (int i = u; i < n; i ++ ) {
            if (used[i]) continue;
            if (tot < curr + nums[i]) continue;
            curr += nums[i]; 
            used[i] = true;
            if (dfs(nums, tot, curr, i + 1, k)) return true;
            else {
                used[i] = false;
                curr -= nums[i];
                if (curr == 0 || curr + nums[i] == tot) return false;
                int k = i;
                while (k < n && nums[k] == nums[i]) k ++ ;
                i = k - 1;
            }
        }
        return false;
    }
};
