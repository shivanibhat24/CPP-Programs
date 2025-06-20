class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int k = 0;
        while(k<n&&nums[k]==0) k++;
        for(int i = n-1;i>=k;i--){
            int target = nums[i];
            int l = 0;
            int r = i-1;
            while(l<r){
                if(nums[l]+nums[r]>target){
                    res+=(r-l);
                    r--;
                }else l++;
            }
        }
        return res;
    }
};
