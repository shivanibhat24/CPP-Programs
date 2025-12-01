class Solution {
public:
    int maxDistinct(string s) {
        int bit = 0;
        for(auto& ch : s) bit |= (1<<(ch-'a'));
        return __builtin_popcount(bit);
    }
};
