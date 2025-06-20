class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int prev_level = -1;
        while(!q.empty()) {
            auto last_pair = q.front();
            q.pop();
            if(last_pair.second > prev_level) {
                prev_level = last_pair.second;
                ans = last_pair.first->val;
            }
            TreeNode* last_node = last_pair.first;
            int last_level = last_pair.second;
            if(last_node->left) q.push({last_node->left, last_level+1});
            if(last_node->right) q.push({last_node->right, last_level+1});
        }
        return ans;
    }
};
