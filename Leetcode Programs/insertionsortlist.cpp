class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* curr=head;
        while(curr->next){
            ListNode* prev=dummy;
            ListNode* after=curr->next;
            if(after->val<curr->val){
                while(prev->next && prev->next->val<after->val){
                    prev=prev->next;
                }
                curr->next=after->next;
                after->next=prev->next;
                prev->next=after;
            }else{
                curr=curr->next;
            }
        }
        return dummy->next;
    }
};
