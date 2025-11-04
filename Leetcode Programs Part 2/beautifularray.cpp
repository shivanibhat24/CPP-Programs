class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> nums{1};
        while(nums.size()<n){
            vector<int> temp;
            for(int x:nums){
                if(2*x-1 <= n) temp.push_back(2*x-1);
            }
            for(int x:nums){
                if(2*x <= n) temp.push_back(2*x);
            }
            nums=temp;
        }
        return nums;
    }
};
