class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> even(2*n + 1, 0), odd(2*n + 1, 0);
        even[n]++;
        int diff = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < k)
                diff++;
            if (nums[i] > k)
                diff--;            
            int len = i+1;
            if (len % 2 == 0) {
                ans += even[n + diff + 1];
                ans += odd[n + diff];
                even[n + diff]++;
            }
            else {
                ans += even[n + diff];
                ans += odd[n + diff + 1];
                odd[n + diff]++;
            }
        }
        return ans;
    }
};
