class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != NULL) {
            slow = slow->next;
        }

       ListNode*curr=slow;
       ListNode*prev=NULL;
       while(curr!=NULL){
        ListNode*after=curr->next;
        curr->next=prev;
        prev=curr;
        curr=after;
       }
       ListNode*first=head;
       ListNode*second=prev;
        while (second != NULL) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
