class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k,j=k;
        int n  = nums.size();
        int maxi = nums[k],mini = nums[k];
        while( i>0 || j<n-1 ){
        if(i==0){
            j++;
        }
        else if(j==n-1)i--;
      else  if(nums[i-1] < nums[j+1]){
            j++;
        }
        else{
            i--;
        }
        mini = min(mini , min(nums[j],nums[i]));
        maxi = max(maxi  , (j-i+1)*mini);
        }
        return maxi;
    }
};
