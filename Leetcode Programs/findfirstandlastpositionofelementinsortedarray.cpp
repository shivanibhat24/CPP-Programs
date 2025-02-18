class Solution {
public:
    int bs(vector<int>& nums, int target, bool left){
        int l = 0;
        int r = nums.size() - 1;
        int prev = l;
        if (left && nums[l] == target){
            return l;
        }
        if (!left && nums.back() == target){
            return r;
        }
        while (l <= r){
            int m = (r + l) / 2;
            if (nums[m] == target){
                prev = m;
                if (left){
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }else if (nums[m] < target){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (nums[prev] == target) {
            return prev;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return {-1, -1};
        }        
        int l = 0;
        int r = nums.size() - 1;
        if (nums[l] == target && nums[r] == target){
            return {l, r};
        } 
        return { bs(nums, target, true),bs(nums, target, false)};
    }
};
