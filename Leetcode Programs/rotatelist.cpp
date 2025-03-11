class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)return head;
        ListNode*temp=head;
        int c=1;
        while(temp->next){
            temp=temp->next;
            c++;
        }
        k=k%c;
        if(k==0){
            temp->next=NULL;
            return head;
        }
        temp->next=head;
        ListNode* newtail=head;
        for(int i=1;i<c-k;i++){
            newtail=newtail->next;
        }
        ListNode*newhead=newtail->next;
        newtail->next=NULL;
        return newhead; 
    }
};
