class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode a(0);
        ListNode* b = &a;
        int c=0;
        while(l1 != nullptr || l2 != nullptr || c>0)        
        {
        if(l1 != nullptr)
        {
            c += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr)
        {
            c += l2->val;
            l2 = l2->next;
        }
        b->next = new ListNode(c%10);
        c /= 10;
        b = b-> next;
        }
        return a.next;

    }
};
