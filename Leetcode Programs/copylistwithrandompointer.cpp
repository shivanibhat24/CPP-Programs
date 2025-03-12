class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hashMap;
        Node *current = head;
        while(current != NULL)
        {
            Node* copy = new  Node(current->val);
            hashMap[current] = copy;
            current = current->next; 
        }
        current = head;
        while(current != NULL)
        {
            Node* copy = hashMap[current];
            if(current->next == NULL)
            {
                copy->next = NULL;
            }
            else
            {
                copy->next = hashMap[current->next];
            }
             if(current->random == NULL)
            {
                copy->random = NULL;
            }
            else
            {
                copy->random = hashMap[current->random];
            }
            current = current->next;
        }
        return hashMap[head];
    }
};
