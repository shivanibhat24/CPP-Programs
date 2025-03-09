class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(int i = 1; n / pow(5, i) >= 1; i++) {
            res += n / pow(5, i); 
        }
        return res; 
    }
};
