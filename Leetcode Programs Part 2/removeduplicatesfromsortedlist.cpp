class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) {
            return head;
        }
        if(head->next == NULL) {
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr != NULL) {
            if(curr->val != prev->val) {
                curr = curr->next;
                prev = prev->next;
            }
            else {
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                curr = prev->next;
            }
        }
        return head;
    }
};
