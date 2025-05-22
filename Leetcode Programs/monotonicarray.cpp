class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(*(nums.begin())<=*(nums.rbegin())){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]){
                    return false;
                }
            }
        }else if(*(nums.begin())>=*(nums.rbegin())){
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]<nums[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};
