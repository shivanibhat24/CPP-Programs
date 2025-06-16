class Solution {
public:
    int tree_cnt = 1;
    unordered_map<long long, int> tree;
    unordered_set<long long> s;
    vector<TreeNode*> ret;
    int getTree(TreeNode* root){
        if(root == nullptr)
            return 0;
        int left_tree = getTree(root->left);
        int right_tree = getTree(root->right);
        long long key = 
            (long long)(root->val + 200) << 32 |
            left_tree << 16 |
            right_tree;
        if(tree[key] == 0)
            tree[key] = tree_cnt++;
        else{
            if(s.count(tree[key]) == 0)
                ret.push_back(root);
            s.insert(tree[key]);
        }
        return tree[key];
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        getTree(root);
        return ret;
    }
};
