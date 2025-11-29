class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int moves=0;
        int n = nums.size();
        int check=nums[nums.size()-1];
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<check){
                moves = moves + (n-i-1);
                check=nums[i];
            }
        }
        return moves;
    }
};
