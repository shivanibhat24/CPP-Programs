class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==3) return nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        if(ans>target) return ans;
        int max=nums[n-1]+nums[n-2]+nums[n-3];
        if(max<target) return max;
        int first=nums[0];
        int second,third,num;
        int diff=abs(ans-target);
        int sum_final;
        for(int i=0;i<n-2;i++)
        {
            if(i&&nums[i]==first) continue;
            first=nums[i];
            second=i+1;
            third=n-1;
            while(second<third)
            {
                sum_final=first+nums[second]+nums[third];
                if(sum_final==target) return sum_final;
                if(abs(sum_final-target)<diff)
                {
                    ans=sum_final;
                    diff=abs(sum_final-target);
                }
                if(sum_final<target)
                {
                    while(second<third&&nums[second]==nums[second+1]) second++;
                    second++;
                }
                if(sum_final>target)
                {
                    while(second<third&&nums[third]==nums[third-1]) third--;
                    third--;
                }
            }
        }
        return ans;
    }
};
