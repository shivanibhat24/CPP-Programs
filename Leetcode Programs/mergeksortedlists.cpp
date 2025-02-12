bool cmp(ListNode* first, ListNode* second) {
    return first->val < second->val;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {        
        if (lists.empty()) {
            return nullptr;
        }        
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            int n = lists.size();
            for (int i = 0; i < n; i += 2) {
                ListNode* first = lists[i];
                ListNode* second = (i + 1) < n ? lists[i + 1] : nullptr;

                mergedLists.push_back(mergeTwoLists(first, second));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        ListNode *dummy, *curr;
        if (!first) {
            return second;
        }
        if (!second) {
            return first;
        }  
        dummy = new ListNode(0);
        curr = dummy;
        while (first && second) {
            if (first->val < second->val) {
                curr->next = first;
                first = first->next;
            } else {
                curr->next = second;
                second = second->next;
            }
            curr = curr->next;
        }
        if (first) {
            curr->next = first;
            first = first->next;
        } else {
            curr->next = second;
            second = second->next;
        }
        return dummy->next;
    }
};
