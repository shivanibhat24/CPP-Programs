class Solution {
public:
    long long countAtLeast(vector<int>& nums, long long comp, long long ans = 0) {
        int i = 0, j = nums.size() - 1;
        while (i < j) 
            if (nums[i] + nums[j] >= comp) 
                ans += (j - i), --j;
            else i++;
            
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countAtLeast(nums, lower) - countAtLeast(nums, upper + 1);
    }
};
