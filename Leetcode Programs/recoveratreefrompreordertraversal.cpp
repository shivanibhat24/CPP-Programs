class Solution {
public:
    string s;
    int idx = 0, level = 0;
    TreeNode* recoverFromPreorder(string traversal) {
        s = traversal;
        TreeNode* node = new TreeNode(-1);
        helper(node, 0);
        return node->left;
    }
    void helper(TreeNode* parent, int lvl) {
        while (idx < s.length() && lvl == level) {
            int num = 0;
            while (idx < s.length() && isdigit(s[idx])) {
                num = num * 10 + (s[idx++] - '0');
            }
            TreeNode* node = new TreeNode(num);
            if (!parent->left)
                parent->left = node;
            else
                parent->right = node;
            level = 0;
            while (idx < s.length() && s[idx] == '-') {
                level++;
                idx++;
            }
            helper(node, lvl + 1);
        }
    }
};
