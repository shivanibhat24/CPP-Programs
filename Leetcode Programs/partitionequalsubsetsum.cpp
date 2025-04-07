class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if(s%2) return false;
        bitset<10001> bit(1);
        for(auto i : nums){
            bit |= bit<<i;
            if(bit[s/2]) return bit[s/2];
        }
        return bit[s/2];
    }
};
