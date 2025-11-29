class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val) ;
        TreeNode* curr = root ;
        while(curr != NULL)
        {
            int data = curr->val ;
            if(data > val)
            {
                if(curr->left) curr = curr->left ;
                else{
                    TreeNode* node = new TreeNode(val) ;
                    curr->left = node ;
                    break ;
                }
            }
            else{
                if(curr->right) curr = curr->right ;
                else{
                    TreeNode* node = new TreeNode(val) ;
                    curr->right = node ;
                    break ;
                }
            }
        }
        return root ;
    }
};
