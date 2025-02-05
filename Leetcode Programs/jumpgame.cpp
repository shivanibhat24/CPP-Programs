class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= jump) {
                jump = i;
            }
        }
        return jump == 0;        
    }
};
