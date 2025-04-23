class Solution {
public:
void helper(vector<int>& nums, vector<int>& sub, vector<vector<int>>& res, int idx) {
       int l=nums.size();
        if(idx==l){
            if(sub.size()>=2)
            res.push_back(sub);
            return;
        }
        if(sub.empty() || nums[idx]>=sub.back()){
        sub.push_back(nums[idx]);
        helper(nums,sub,res,idx+1);        
        sub.pop_back();
        }
        if(sub.empty() || nums[idx]!=sub.back())
        helper(nums,sub,res,idx+1);
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;

        vector<int> sub;
        helper(nums, sub, res, 0);
        return res;
    }
};
