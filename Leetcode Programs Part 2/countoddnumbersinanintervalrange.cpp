class Solution {
public:
    int countOdds(int l, int h) {
        if(l&1)return (h-l+2)/2;
        return (h-l+1)/2;
    }
};
