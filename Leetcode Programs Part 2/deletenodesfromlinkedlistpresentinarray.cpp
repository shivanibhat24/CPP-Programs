class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int max = -1;
        for (int num : nums) {
            max = num > max ? num : max;
        }
        vector<bool> freq(max + 1, false);
        for (int num : nums) {
            freq[num] = true;
        }
        ListNode* temp = new ListNode();
        ListNode* current = temp;
        while (head != nullptr) {
            if (head->val >= freq.size() || !freq[head->val]) {
                current->next = head;
                current = current->next;
            }
            head = head->next;
        }
        current->next = nullptr;
        return temp->next;
    }
};
