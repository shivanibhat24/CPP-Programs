class Solution {
    void fxn(TreeNode* node, int targetSum, long & ans, map<long,long> & st,long currSum){
        if(node==NULL){
            return;
        }
        int val = node->val;
        currSum+=val;
        if(st.find(-targetSum+currSum)!=st.end()){
            ans+=st[-targetSum+currSum];
        } 
        if(targetSum==currSum){
            ans+=1;
        }
        st[currSum]++;
        fxn(node->left, targetSum, ans, st,currSum);
        fxn(node->right, targetSum, ans, st,currSum);
        st[currSum]--;
        currSum-=val;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        map<long,long>st;
        long ans =0;
        fxn(root, targetSum, ans, st,0);
        return ans;
    }
};
