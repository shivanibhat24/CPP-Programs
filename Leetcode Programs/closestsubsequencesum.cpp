#define ll long long
class Solution {
public:
    int n,fill;
    int lsum[1<<20];
    int rsum[1<<20];
    inline void collect(vector<int>& nums,int s,int r,int i,int sum[])
    {
        if(i==r) sum[fill++]=s;
        else{
            int j=i+1;
            while(j<r&&nums[j]==nums[i]){
                ++j;
            }
            for(int k=0;k<=j-i;k++){
                collect(nums,s+k*nums[i],r,j,sum);
            }
        }
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        ios::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        n=nums.size();
        ll posSum=0,negSum=0;
        for(auto& num:nums){
            num>0?posSum+=num:negSum+=num;
        }
        if(posSum<goal) return abs(posSum-goal);
        if(negSum>goal) return abs(negSum-goal);
        ranges::sort(nums);//剪枝
        int l_size,r_size;
        collect(nums,0,n>>1,0,lsum);
        l_size=fill;
        fill=0;
        collect(nums,0,n,n>>1,rsum);
        r_size=fill;
        sort(lsum,lsum+l_size);
        sort(rsum,rsum+r_size);
        int ans=INT_MAX;
        for(int i=r_size-1,j=0;j<l_size;j++){
            while(i>=0&&abs(lsum[j]+rsum[i-1]-goal)<=abs(lsum[j]+rsum[i]-goal)){
                i--;
            }
            ans=min(ans,abs(lsum[j]+rsum[i]-goal));
        }
        return ans;
    }
};
