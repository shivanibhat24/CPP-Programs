class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        return popcount(1u*gcd(targetX,targetY)) == 1;
    }
};
