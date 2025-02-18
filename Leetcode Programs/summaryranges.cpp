class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans; 
    int n=nums.size();
    int i=0;
    for(i=0;i<n-1;i++){
        int count=0;
        int start=nums[i];
        while(i<n-1 && nums[i+1]==nums[i]+1){
            i++;
            count++;
        }
        int end=nums[i];
    if(count>0)ans.push_back(to_string(start)+"->" + to_string(end));
    else ans.push_back(to_string(nums[i]));
    }
    if(i<n) ans.push_back(to_string(nums[i]));
    return ans;       
    }
};
