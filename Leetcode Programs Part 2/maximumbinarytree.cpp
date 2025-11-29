class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> st;
        for (int i=0;i<nums.size();++i){
            TreeNode* curr = new TreeNode(nums[i]);
            while (!st.empty() && curr->val>st.back()->val){
                curr->left=st.back();st.pop_back();
            }
            if (!st.empty()){
                st.back()->right = curr;
            }
            st.push_back(curr);
        }
        return st.front();
    }
};
