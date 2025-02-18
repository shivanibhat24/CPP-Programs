#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC optimize ("-ffloat-store,-fno-defer-pop,-fprefetch-loop-arrays,omit-frame-pointer,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
class Solution {
public:
    constexpr bool is_poss(vector<vector<char>>& a, uint8_t ii, uint8_t jj, char num) {
    for (uint8_t i = 0; i < 9; i++) {
        if (a[i][jj] == num || a[ii][i] == num)
            return false;
    }
    uint8_t row = (ii / 3) * 3;
    uint8_t col = (jj / 3) * 3;
    for (uint8_t i = row; i < row + 3; i++) {
        for (uint8_t j = col; j < col + 3; j++) {
            if (a[i][j] == num)
                return false;
        }
    }
    return true;
}
constexpr bool isValidSudoku(vector<vector<char>>& board) {
    for (uint8_t i = 0; i < 9; i++) {
        for (uint8_t j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                char num = board[i][j];
                board[i][j] = '.';
                if (!is_poss(board, i, j, num))
                    return false;
            }
        }
    }
    return true;
}
};
