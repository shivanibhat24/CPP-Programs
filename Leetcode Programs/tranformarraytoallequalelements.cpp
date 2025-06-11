class Solution {
public:
    bool tryTarget(vector<int> nums, int k, int target) {  
        int ops = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != target) {
                nums[i] *= -1;
                nums[i + 1] *= -1;
                ops++;
            }
        }
        for (int x : nums) {
            if (x != target)
                return false;
        }
        return ops <= k;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        return tryTarget(nums, k, -1) || tryTarget(nums, k, 1);
    }
};
