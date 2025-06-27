class Solution {
public:
    int dfs(TreeNode* root, unordered_map<int, int>& mp) {
        int lS = 0;
        int rS = 0;
        if (root->left) lS = dfs(root->left, mp);
        if (root->right) rS = dfs(root->right, mp);
        int currSum = root->val + lS + rS;
        mp[currSum] += 1;
        return currSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        dfs(root, mp);
        vector<int> res;
        int maxCount = INT_MIN;
        for (const auto& kv : mp) {
            if (kv.second > maxCount) {
                maxCount = kv.second;
                res = {kv.first};
            } else if (kv.second == maxCount) {
                res.emplace_back(kv.first);
            }
        }
        return res;
    }
};
