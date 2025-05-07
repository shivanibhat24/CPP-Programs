class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
        for (int &x : nums) x = __builtin_popcount(x);
        sort(nums.begin(), nums.end());
        int ptrLeft = 0;
        long long ret = 0;
        int n = nums.size();
        for (int ptrRight = n - 1; ptrRight >= 0; ptrRight--) {
            while (ptrLeft < n && nums[ptrLeft] + nums[ptrRight] < k)
                ptrLeft++;
            ret += n - ptrLeft;
        }
        return ret;
    }
};
