class Solution {
public:
int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int totsum=0;
        int prodsum=0;
        for(int i=0;i<n;i++){
            totsum+=nums[i];
            prodsum+=nums[i]*i;
        }
        int maxi=INT_MIN;
        maxi=max(prodsum,maxi);
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum=prodsum;
           sum-=nums[i]*(n-1);
           sum+=totsum-nums[i];
           maxi=max(sum,maxi);
           prodsum=sum;
        }
        return maxi;         
    }
};
