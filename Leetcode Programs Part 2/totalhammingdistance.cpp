class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {        
        int ans = 0;
        for(int i = 0 ; i < 32; i++){
            int num = 0;
            for(auto &j : nums){
                num += 1 ^ (((j & (1LL << i))!= 0));
            }
            ans += (num * (nums.size() - num));
        }
        return ans;
    }
};
