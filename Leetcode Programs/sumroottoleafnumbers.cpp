class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }    
    int helper(TreeNode* root, int currentSum) {
        if (!root) return 0;
        currentSum = currentSum * 10 + root->val;
        if (!root->left && !root->right) return currentSum;
        return helper(root->left, currentSum) + helper(root->right, currentSum);
    }
};
