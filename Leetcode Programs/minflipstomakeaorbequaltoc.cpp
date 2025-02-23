class Solution {
public:
    int minFlips(int a, int b, int c) {
        int temp;
        temp= (a|b)^c;
        int r1= (a&b);
        int r2= temp&r1;
        return __builtin_popcount(temp)+ __builtin_popcount(r2);
    }
};
