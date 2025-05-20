class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        std::vector<int> d(nums.size()+1);        
        d[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            d[i] = nums[i] - nums[i-1];
        }
        for (const auto& q : queries) {
            d[q[0]]--;
            d[q[1]+1]++;
        }
        int p = 0;
        for (int i = 0; i < nums.size(); ++i) {
            p += d[i];
            if (p > 0) {
                return false;
            }
        }
        return true;
    }
};
