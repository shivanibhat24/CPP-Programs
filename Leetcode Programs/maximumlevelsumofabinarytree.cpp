/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        std::queue<TreeNode*> queue;
        int max(root->val);
        int maxlevel(1), curlevel(1);
        queue.push(root);

        while (!queue.empty()) {
            size_t s = queue.size();
            int sum(0);
            for (auto i(0); i<s; ++i) {
                TreeNode *ptr = queue.front();
                queue.pop();
                sum += ptr->val;

                if (ptr->left)
                    queue.push(ptr->left);
                if (ptr->right)
                    queue.push(ptr->right);
            }
            if (sum > max)  {
                max = sum;
                maxlevel = curlevel;
            }
            ++curlevel;
        }
        return maxlevel;
    }
};
