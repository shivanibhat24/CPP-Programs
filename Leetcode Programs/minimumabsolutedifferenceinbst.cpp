class Solution {
private:
    int minDifference = INT_MAX, prevValue = -1;
public:    
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return minDifference;
        getMinimumDifference(root->left);
        if (prevValue >= 0) {
            minDifference = min(minDifference, root->val - prevValue);
        }
        prevValue = root->val;
        getMinimumDifference(root->right);
        return minDifference;
    }
};
