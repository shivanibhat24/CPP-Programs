class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* second = dummy;
        int f = second->next->val;
        while(second->next&&second->next->next){
                if(second->next->next->val==f){
                    while(second->next&&second->next->val==f){
                        ListNode* temp = second->next;
                        second->next = second->next->next;
                        temp=nullptr;

                    }
                    if(second->next)
                    f=second->next->val;
                }
                else{
                    second=second->next;
                    f=second->next->val;
                }
        }        
        return dummy->next;
    }
};
