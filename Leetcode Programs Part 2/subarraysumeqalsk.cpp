class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0] = 1;
        int s = 0, ans = 0;
        for(auto it:nums){
            s+=it;
            ans += mp[s-k];
            mp[s]++;
        }
        return ans;
    }
};
