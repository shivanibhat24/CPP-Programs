class Solution {
public:
    static int coinChange(vector<int>& coins, const uint target) {
        if (target == 0)
            return 0;
        const uint n = coins.size();
        if (n == 1)
            return target % coins.front() ? -1 : target / coins[0];
        sort(coins.begin(), coins.end());
        const uint minCoin = coins.front();
        if (target == minCoin)
            return 1;
        uint idx = 1, gcdVal = minCoin;
        for (; idx < n && target >= coins[idx]; idx++) {
            if (target == coins[idx])
                return 1;
            gcdVal = gcd(coins[idx], gcdVal);
            coins[idx] -= minCoin;
        }
        if (target % gcdVal != 0)
            return -1;

        const uint minVal = (target - 1u) / (coins[idx - 1u] + minCoin) + 1u,
                   maxVal = target / minCoin;
        for (uint i = minVal; i <= maxVal; i++) {
            if (findCombination(coins, 1, idx - 1u, target - i * minCoin, i))
                return i;
        }
        return -1;
    }
    static bool findCombination(const vector<int>& coins, const uint left,
                                const uint right, const uint target,
                                const uint maxCoins) {
        if (!target)
            return true;
        if (target < coins[left] || target / coins[right] > maxCoins)
            return false;
        if (!(target % coins[right]))
            return true;
        if (left == right)
            return false;
        for (uint k = target / coins[right] + 1u; k--;) {
            if (findCombination(coins, left, right - 1u,
                                target - k * coins[right], maxCoins - k))
                return true;
        }
        return false;
    }
};
