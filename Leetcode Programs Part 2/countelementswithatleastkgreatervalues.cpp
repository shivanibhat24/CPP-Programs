class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return n;
        int targetIndex = n - k;
        nth_element(nums.begin(), nums.begin() + targetIndex, nums.end());
        int T = nums[targetIndex];
        int countGT = 0, countEQ = 0, countLT = 0;
        for (int x : nums) {
            if (x > T) countGT++;
            else if (x == T) countEQ++;
            else countLT++;
        }
        if (countGT >= k) {
            return countLT + countEQ;
        } else {
            return countLT;
        }
    }
};
