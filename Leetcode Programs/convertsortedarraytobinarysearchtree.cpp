class Solution {
public:
    TreeNode* builtTree(vector<int>& nums, int start, int end){
        if(start>end) return nullptr;
        int mid = start+(end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->right = builtTree(nums, mid+1, end);
        root->left = builtTree(nums, start,mid-1);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return builtTree(nums, 0, nums.size()-1);
    }
};
