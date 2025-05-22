class Solution {
public:
    bool isTreeBalanced = true;
    int depth(TreeNode* root) {
        if (!root) return 0;
        int lh = depth(root->left);
        int rh = depth(root->right);
        if (isTreeBalanced && abs(lh - rh) > 1) {
            isTreeBalanced = false;
        }
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        depth(root);
        return isTreeBalanced;
    }
};
