class Solution {
public:
    int preorderIndex;
    vector<int> preorder;
    unordered_map<int, int> mapping;
    TreeNode* buildTree(vector<int>& _p, vector<int>& inorder) {
        preorder = _p;
        mapping.clear();
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }
        preorderIndex = 0;
        return build(0, inorder.size() - 1);
    }
    TreeNode* build(int start, int end) {
        if (start > end)
            return nullptr;
        int val = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(val);
        int mid = mapping[val];
        root->left = build(start, mid - 1);
        root->right = build(mid + 1, end);
        return root;
    }
};
