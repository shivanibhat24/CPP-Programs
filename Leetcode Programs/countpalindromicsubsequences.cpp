class Solution {
public:
    int countPalindromes(const string& s) noexcept {
        array<int, 10> leftNumCnt, rightNumCnt, leftPrs[10], rightPrs[10];
        long result = 0;
        for (char digit : s) {
            char c = digit - '0';
            for (size_t i = 0; i <= 9; ++i) {
                rightPrs[i][c] += rightNumCnt[i];
            }
            ++rightNumCnt[c];
        }
        for (char digit : s) {
            char c = digit - '0';
            --rightNumCnt[c];
            for (size_t ind = 0; ind < 10; ++ind) {
                rightPrs[c][ind] -= rightNumCnt[ind];
            }
            for (size_t i = 0; i <= 9; ++i) 
                for (size_t j = 0; j <= 9; ++j)
                    result += (long) rightPrs[i][j] * leftPrs[i][j];
            for (size_t ind = 0; ind < 10; ++ind) {
                leftPrs[c][ind] += leftNumCnt[ind];
            }
            ++leftNumCnt[c];
        }
        return result % 1000000007;
    }
};
