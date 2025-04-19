class Solution {
    public:
        long long countFairPairs(vector<int>& nums, int lower, int upper, long long ans = 0) {
            for(int i = 0 ; i < nums.size(); i++)
                for(int j = i + 1; j < nums.size(); j++)
                    if(nums[i] + nums[j] >= lower && nums[i] + nums[j] <= upper) ++ans;
    
            return ans;
        }
    };
