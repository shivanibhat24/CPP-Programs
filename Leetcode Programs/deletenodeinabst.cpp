class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        while (curr != nullptr) {
            if (curr->val == key) {
                // Found node 'key', remove it.
                moveRightSubtreeToLeftSubtree(curr);
                TreeNode* newSubtree = curr->left;
                if (curr == root) {
                    return newSubtree;
                } else {
                    if (parent->left == curr) {
                        parent->left = newSubtree;
                    } else {
                        parent->right = newSubtree;
                    }
                    return root;
                }
            } else if (key < curr->val) {
                parent = curr;
                curr = curr->left;
            } else {
                parent = curr;
                curr = curr->right;
            }
        }

        return root;
    }

private:

    void moveRightSubtreeToLeftSubtree(TreeNode* node) {
        if (node->left == nullptr) {
            node->left = node->right;
            node->right = nullptr;
            return;
        }
        TreeNode* maxInLeft = node->left;
        while (maxInLeft->right != nullptr) {
            maxInLeft = maxInLeft->right;
        }
        // 'maxInLeft' is the max node in left subtree.
        maxInLeft->right =  node->right;
        node->right = nullptr;
    }
};
