class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int,int> &mp){
        if(inStart > inEnd || postStart > postEnd) {
            return nullptr;;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int numLeft = mp[postorder[postEnd]];
        root->left = helper(inorder,postorder,inStart,numLeft-1,postStart,postStart+numLeft-inStart-1,mp);
        root->right = helper(inorder,postorder,numLeft+1,inEnd,postStart+numLeft-inStart,postEnd-1,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp);
    }
};
