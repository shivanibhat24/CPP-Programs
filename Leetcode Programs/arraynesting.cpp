class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int c =0;
        int maxc = 1;
        int i = nums[0];
        for(int j = 0;j<n;j++) {
            c = 0;
            i = j;
            if(nums[i] != 0 && nums[i] >= 0) {
                while(nums[i] >= 0) {
                    c++;
                    nums[i] *= -1;
                    i = -1*nums[i];
                }
            }
            maxc = max(maxc, c);
        }
        return maxc;
    }
};
