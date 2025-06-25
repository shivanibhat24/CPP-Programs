class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            res|=nums[i];
        return res;
    }
};
