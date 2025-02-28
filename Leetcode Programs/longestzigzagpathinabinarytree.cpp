class Solution {
public:
    int dfs(TreeNode* root, int isLeft, int cnt) {
        if (!root) return cnt;
        if (isLeft) return max(dfs(root->right, 0, cnt + 1), dfs(root->left, 1, 0));
        return max(dfs(root->left, 1, cnt + 1), dfs(root->right, 0, 0));
    }
    int longestZigZag(TreeNode* root) {
        return max(dfs(root->left, 1, 0), dfs(root->right, 0, 0));
    }
};
