class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int m){
        int cur=1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>m) return false;
            sum+=nums[i];
            if(sum>m){
                cur++;
                sum=nums[i];
            }
        }
        if(cur<=k) return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=-1,r=1e9+1;
        while(l+1<r){
            int m=(l+r)/2;
            if(isPossible(nums,k,m)){
                r=m;
            }
            else{
                l=m;
            }
        }
        return r;
    }
};
