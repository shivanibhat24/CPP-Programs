class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        TreeNode* node = root;
        while(node){
            if(node->left){
                TreeNode* rightMost = node->left;
                while(rightMost->right){
                    rightMost = rightMost->right;
                }
                rightMost->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            node = node->right;
        }
    }
};
