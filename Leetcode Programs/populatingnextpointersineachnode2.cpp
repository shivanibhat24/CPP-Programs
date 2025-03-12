class Solution {
public:
    Node* connect(Node* root) {
   if (!root) return nullptr;
    Node* levelStart = root;
    while (levelStart) {
        Node* current = levelStart;
        Node* dummy = new Node(0);  
        Node* nextLevel = dummy;
        while (current) {
            if (current->left) {
                nextLevel->next = current->left;
                nextLevel = nextLevel->next;
            }
            if (current->right) {
                nextLevel->next = current->right;
                nextLevel = nextLevel->next;
            }
            current = current->next;
        }
        levelStart = dummy->next;
    }
    return root;        
    }
};
