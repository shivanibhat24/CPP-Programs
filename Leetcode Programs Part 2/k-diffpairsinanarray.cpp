class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = 1, res = 0;
        while (r < n) {
            if (l == r || nums[r] - nums[l] < k) {
                r++;
            } 
            else if (nums[r] - nums[l] > k) {
                l++;
            } 
            else { 
                res++;
                l++; 
                r++;
                while (r < n && nums[r] == nums[r - 1]){
                    r++; 
                } 
            }
            if (l == r){
                r++; 
            } 
        }
        return res;
    }
};
