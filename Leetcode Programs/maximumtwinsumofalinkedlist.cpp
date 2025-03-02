class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        vector<int>ans;
        while(temp!=nullptr){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int sum=0;
        int n=ans.size();
        for(int i=0;i<n/2;i++){
            sum=max(sum,ans[i]+ans[n-i-1]);
        }
        return sum;
    }
};
