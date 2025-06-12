
class Solution {
    void collectNodes(unordered_map<int, TreeNode*>& mp, TreeNode* node) {
        if(!node) return;
        mp[node->val] = node;
        collectNodes(mp, node->left);
        collectNodes(mp, node->right);
    }
    void makeTree(unordered_map<int, TreeNode*>& mp, TreeNode*& node, int& cnt) {

        if(!node) return;
        if(!node->left && !node->right && mp[node->val]) {
            node = mp[node->val];
            mp[node->val] = NULL;
            cnt++;
        }
        makeTree(mp, node->left, cnt);
        makeTree(mp, node->right, cnt);
    }
    
    bool validateBST(TreeNode* root, TreeNode* low, TreeNode* high) {
        
        if(!root) return true;
        if((low && root->val <= low->val) || 
           (high && root->val >= high->val)) return false;
        
        return validateBST(root->left, low, root) && 
                validateBST(root->right, root, high);
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        
        if(trees.size() == 1) {
            return validateBST(trees[0], NULL, NULL) ? trees[0] : NULL;
        }
        unordered_map<int, TreeNode*> mp;
        for(auto& node: trees) {
            collectNodes(mp, node->left);
            collectNodes(mp, node->right);
        }
        TreeNode* root = NULL;
        for(auto& node: trees) {
            if(mp.count(node->val)) mp[node->val] = node;
            else if(root) return NULL;
            else root = node;
        }
        if(!root) return NULL;
        int cnt = 0;
        makeTree(mp, root, cnt);
        if(cnt != mp.size()) return NULL;        
        return validateBST(root, NULL, NULL) ? root : NULL;
    }
};
