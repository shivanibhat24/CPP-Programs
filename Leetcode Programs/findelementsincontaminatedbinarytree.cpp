bitset<2097152> hasX = 0; // 2097152=2**21
class FindElements {
public:
    TreeNode* root;
    FindElements(TreeNode* root) { dfs(root, 0); }
    ~FindElements() { hasX = 0; }
    void dfs(TreeNode* root, int x) {
        if (!root)
            return;
        root->val = x;
        hasX[x] = 1;
        dfs(root->left, 2 * x + 1);
        dfs(root->right, 2 * x + 2);
    }
    bool find(int target) { return hasX[target]; }
};
