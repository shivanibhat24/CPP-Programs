class Solution {
public:
    map<int, pair<double, int>> mp;
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        solver(root, 0);
        for (auto i : mp) {
            res.push_back(i.second.first / i.second.second);
        }
        return res;
    }
    void solver(TreeNode* root, int curDep) {
        if (root == NULL) {
            return;
        }
        mp[curDep].first += root->val;
        mp[curDep].second++;
        solver(root->left, curDep + 1);
        solver(root->right, curDep + 1);
    }
};
