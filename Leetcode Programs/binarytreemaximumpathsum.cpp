class Solution {
public:
    int maxSum(TreeNode* node, int& maxi){
        if(node==NULL){
            return 0;
        }
        int lsum=max(0,maxSum(node->left,maxi));
        int rsum=max(0,maxSum(node->right,maxi));
        maxi=max(maxi,lsum+rsum+node->val);
        return node->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxSum(root,maxi);
        return maxi;
    }
};
