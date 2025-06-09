class Solution {
public:
    const int MOD = 1e9 + 7; 
    int countOrders(int numberOfPairs) {
        long long count = 1 ;
        for (int currentPairs = 1; currentPairs <= numberOfPairs; currentPairs++) {
            count = count * (2 * currentPairs - 1) * currentPairs % MOD;
        }
        return count; 
    }
};
