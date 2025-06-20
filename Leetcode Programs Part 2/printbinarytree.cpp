class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void fill(TreeNode* root, vector<vector<string>>& res, int row, int left, int right) {
        if (!root || left > right) return;
        int mid = (left + right) / 2;
        res[row][mid] = to_string(root->val);
        fill(root->left, res, row + 1, left, mid - 1);
        fill(root->right, res, row + 1, mid + 1, right);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int maxSize = pow(2, h) - 1;
        vector<vector<string>> res(h, vector<string>(maxSize, ""));
        fill(root, res, 0, 0, maxSize - 1);
        return res;
    }
};
