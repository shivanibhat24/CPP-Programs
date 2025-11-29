class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int n1=INT_MAX;
        int n2=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < n1){
                n1=nums[i];
            }
            if(nums[i] > n2){
                n2=nums[i];
            }
        }

        int end=min(n1,n2);
        int ans=0;
        for(int i=1;i<=end;i++){
            if((n1%i==0) && (n2%i==0)){
                ans=i;
            }
        }
        return ans;
    }
};
