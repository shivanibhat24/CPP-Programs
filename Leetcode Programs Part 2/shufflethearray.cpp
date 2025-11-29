class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int i=0;
        while(n<nums.size()){
           ans.push_back(nums[i++]);
           ans.push_back(nums[n++]);
        }
        return ans;
    }
};
