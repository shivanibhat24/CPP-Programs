class Solution {
public:
    int path;
    int calc(TreeNode* root) {
        if(root == NULL) return 0; 
        if(root->left == NULL && root->right == NULL)return 0;
        int left = 1 + calc(root->left);
        int right = 1 + calc(root->right);
        if((root->left!=NULL && root->left->val == root->val) &&(root->right!=NULL && root->right->val == root->val)){
            path = max(path, left + right);
        }
        if(root->left==NULL || root->left->val != root->val){
            left = 0;
        }        
        if(root->right==NULL || root->right->val != root->val){
            right = 0;
        }
        path = max(path, max(left, right));
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root){
        int val = calc(root);
        return max(path, val);
    }
};
