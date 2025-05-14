class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int a : nums) {
            ++mp[a];
        }
        vector<vector<int>> t(n + 5);
        for (auto it : mp) {
            t[it.second].push_back(it.first);
        }
        vector<int> ans;
        for (int i = n; i > 0; --i) {
            ans.insert(ans.end(), t[i].begin(), t[i].end());
        }
        ans.resize(k);
        return ans;
    }
};
