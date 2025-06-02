class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        vector<int> digits{};
        int temp = n + 1;
        while (temp > 0) {
            digits.emplace_back(temp % 10);
            temp /= 10;
        }
        int result = 0;
        int len = digits.size();
        int curr = 9;
        for (int i = 0; i < len - 1; i++) {
            result += curr;
            curr *= 9 - i;
        }
        curr /= 9;
        vector<bool> seen(10, false);
        for (int i = 0; i < len; i++) {
            int d = digits[len - i - 1];

            for (int j = i == 0 ? 1 : 0; j < d; j++) if (!seen[j]) result += curr;
            curr /= 9 - i;

            if (seen[d]) break;
            seen[d] = true;
        }
        return n - result;
    }
};
