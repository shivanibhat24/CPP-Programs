class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) 
    {
        int i=-1,j=0;
        int n = nums.size();
        int mn = -1;
        int mx = -1;
        long long ans = 0;
        while(j<n)
        {
            if(nums[j]<mink||nums[j]>maxk)i = j;
            if(mink==nums[j])mn = j;
            if(maxk==nums[j])mx = j;
            if(min(mn,mx)-i>0) ans += (min(mn,mx)-i);
            j++;

        }
        return ans;
        
    }
};
