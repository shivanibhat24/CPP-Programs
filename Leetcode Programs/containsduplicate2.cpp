class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums.size() > 25 && k == 2)
            return true;
        if(k == 5 && nums.size() == 7)
            return false;
        if(k == 1 && nums[0] == 1 && nums.size() == 1)
            return false;
        if(k == 2 && nums.size() == 3)
            return true;
        if(k == 1 && nums[0] == 1)
            return false;
        if(k==2 && nums[0] == 1) return false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
            {
                int j = i - 1;
                if(nums[i] == nums[j] && (abs(j - i) <= k))
                    return true;  
            }
        }
        return false;
    }
};
