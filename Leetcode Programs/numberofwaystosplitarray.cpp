class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int size=nums.size();        
        long totalSum=0;
        for(int num:nums){
            totalSum+=num;
        }
        long leftSum=0;
        int count=0;
        for(int i=0;i<size-1;i++){

            leftSum+=nums[i];
            long rightSum=totalSum-leftSum;

            if(leftSum>=rightSum){
                count++;
            }

        }
        return count;
    }
};
