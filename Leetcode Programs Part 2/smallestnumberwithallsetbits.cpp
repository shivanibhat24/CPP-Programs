class Solution {
public:
    int smallestNumber(int n) {
        for (uint i = 0; n & (n + 1); i++) {
            n |= 1 << i;
        }
        return n;
    }
};
