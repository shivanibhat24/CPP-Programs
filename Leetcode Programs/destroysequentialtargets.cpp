class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> count;
        for(auto num : nums){
            count[num % space]++;
        }
        int maxc = 0;
        for(auto [r, c] : count){
            maxc = max(maxc, c);
        }
        int res = INT_MAX;
        for(auto num : nums){
            if(count[num % space] == maxc){
                res = min(res, num);
            }
        }
        return res;
    }
};
