class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0 ; 
        double sum = 0; 
        for(int i = 0 ; i< k ; i++){
            sum += nums[i]; 
        }
        ans = sum ;
        for(int i = k ; i<nums.size() ; i++){
            sum += nums[i]; 
            sum -= nums[i-k]; 
            ans = max(ans , sum );
        }
        return ans /k ; 
    }
};
