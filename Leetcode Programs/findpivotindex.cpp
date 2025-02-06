class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0, leftTotal = 0;
        for (int num : nums) {
            total += num;
        }
        for (int i = 0; i < nums.size(); ++i) {
            // rightTotal is derived from total - leftTotal - nums[i]
            if (leftTotal == total - leftTotal - nums[i]) {
                return i;
            }
            leftTotal += nums[i];
        }        
        return -1;        
    }
};
