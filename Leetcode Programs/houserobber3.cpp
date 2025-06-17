class Solution {
public:
    pair<int, int> solve(TreeNode* root){
        if(root == NULL) return {0, 0};
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        int incl = root->val + left.second + right.second;
        int excl = max(left.first, left.second) + max(right.first, right.second);
        return {incl, excl};
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};
