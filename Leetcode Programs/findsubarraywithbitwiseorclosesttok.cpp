class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int rightOr = 0;
        int left = 0, mid = 0, right = 0;
        for (int right = 0; right < nums.size(); right++) {
            rightOr |= nums[right];
            while (left <= right && (nums[left] | rightOr) > k) {
                ans = min(ans, (nums[left] | rightOr) - k);
                left++;
                if (mid < left) {
                    for (int i = right - 1; i >= left; i--) {
                        nums[i] |= nums[i+1];
                    }
                    mid = right;
                    rightOr = 0;
                }
            }
            if (left <= right) {
                ans = min(ans, k - (nums[left] | rightOr));
            }
        }
        return ans;
    }
};
