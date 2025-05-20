class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* node = nullptr;
        while (second) {
            ListNode* temp = second->next;
            second->next = node;
            node = second;
            second = temp;
        }
        ListNode* first = head;
        second = node;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
