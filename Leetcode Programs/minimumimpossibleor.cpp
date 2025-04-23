class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int res = 0, i;
        for(int &it: nums) {
            if ((it&(it-1)) == 0) res |= it;
        }
        for(i=1; i<=res; i<<=1) {
            if ((res&i) == 0) return i;
        }
        return i;
    }
};
