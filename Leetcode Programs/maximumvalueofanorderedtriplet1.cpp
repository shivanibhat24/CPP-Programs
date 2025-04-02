class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        long long max_result = 0;
        int max_value = nums[0];
        int max_diff = 0;
        for (int i=1 ; i<n ; i++) {
            max_result = max(max_result , (long long)max_diff * nums[i]);
            max_diff = max(max_diff , max_value - nums[i]);
            max_value = max(max_value , nums[i]);
        }
        return max_result;
    }
};
