class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        helper(root, res, false);
        return res;
    }
    int helper(TreeNode* r, int& res, bool has_parent) {
        if(r) {
            int left = helper(r->left, res, true);
            int right = helper(r->right, res, true);
            if(!left || !right) {
                res++;
                return 1;
            }
            else if(left + right == 3) {
                return 2;
            }
            else if(left + right == 4) {
                if(has_parent) return 0;
                ++res;
                return 1;
            }
        }
        return 2;
    }
};
