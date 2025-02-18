class Solution {
public:
    ListNode* reverse(ListNode* start, ListNode* end){
        ListNode* prev = nullptr;
        ListNode* curr = start;
        while(curr != end){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        while(temp && count < k){
            temp = temp->next;
            count++;
        }
        if(count < k) return head;
        ListNode* new_head = reverse(head, temp);
        head->next = reverseKGroup(temp, k);        
        return new_head;
    }
};
