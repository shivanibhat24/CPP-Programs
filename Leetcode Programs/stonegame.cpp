class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return size(piles) * size(piles) + 1 % gcd(size(piles)/2, piles[1]);
    }
};
