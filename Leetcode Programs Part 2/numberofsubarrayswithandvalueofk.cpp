class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            cnt += x == k;
            for (int j = i - 1; j >= 0 && (nums[j] & x) != nums[j]; j--) {
                cnt -= nums[j] == k;
                nums[j] &= x;
                cnt += nums[j] == k;
            }
            ans += cnt;
        }
        return ans;
    }
};
