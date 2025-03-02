class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> nodeList_root1, nodeList_root2;
        getLeafValues(root1, nodeList_root1);
        getLeafValues(root2, nodeList_root2);
        return nodeList_root1 == nodeList_root2;
    }
    void getLeafValues(TreeNode* node, std::vector<int>& nodeList) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) {
            nodeList.push_back(node->val);
            return;
        }
        getLeafValues(node->left, nodeList);
        getLeafValues(node->right, nodeList);
    }

};
