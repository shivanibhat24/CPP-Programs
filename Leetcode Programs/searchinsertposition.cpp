class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l= 0,r = nums.size()-1;
        int m;
        int indx=0;
        while(l <= r)
        {
            m = (l+r)/2;
            if(nums[m] == target)return m;
            else if(nums[m] < target)
            {
                indx = m+1;
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        return indx;
    }
};
