class Solution {
public:
    int pairSum(ListNode* head) {
      ListNode *f=head,*s=head,*prev=nullptr,*curr=head;
      if(head->next->next==nullptr)
         return head->val+head->next->val;
      while(f->next && f->next->next)
      {
        f=f->next->next;
        s=s->next;
        head=head->next;
        curr->next=prev;
        prev=curr;
        curr=head;
      }
      int ans=s->val+s->next->val;
      s=s->next->next;
      while(prev)
      {
        ans=max(ans,prev->val+s->val);
        prev=prev->next;
        s=s->next;
      }
      return ans;
    }
};
