class Solution {
public:
void helper(TreeNode* root,int target,vector<vector<int>>& ans,vector<int>& temp){
    if(root==NULL) return;
    temp.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        if(target==root->val){
        ans.push_back(temp);
        }
    }
    else{
    helper(root->left,target-root->val,ans,temp);
    helper(root->right,target-root->val,ans,temp);
    }
    temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<vector<int>>ans;
        vector<int>temp;
       helper(root,tar,ans,temp);
      return ans;  
    }
};
