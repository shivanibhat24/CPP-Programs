#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
class Solution {
public:
    void solution(TreeNode* node, int maximum) {
        if(!node) return;
        if(node->val >= maximum) {
            maximum = node->val;
            answer++;
        }
        solution(node->left, maximum);
        solution(node->right, maximum);
        node->left = node->right = nullptr;
    }
    int goodNodes(TreeNode* root) {
        solution(root, root->val);
        return answer;
    }
    int answer = 0;
};
