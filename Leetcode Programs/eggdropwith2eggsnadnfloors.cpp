class Solution {
public:
    int twoEggDrop(int n) {
        return ceil(ceil(-1 + sqrt(1 + 8 * n)) / 2.0);
    }
};
