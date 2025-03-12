class Solution {
public:
    vector<int> v;
    void inOrderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inOrderTraversal(root->left);
        v.push_back(root->val);
        inOrderTraversal(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root);
        return v[k - 1];
    }
};
