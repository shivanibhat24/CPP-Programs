class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode(0, head);
        ListNode* dummy = ans;
        while (dummy != nullptr) {
            while (dummy->next != nullptr && dummy->next->val == val) {
                dummy->next = dummy->next->next;
            }
            dummy = dummy->next;
        }        
        ListNode* result = ans->next;
        delete ans;
        return result;        
    }
};
