class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    constexpr int MOD = 1'000'000'007;
    const int m = r - l + 1;
    vector<int> dp(m, 1);
    for (int i = 2; i <= n; ++i) {
      if (i % 2 == 0) {
        int pre = 0;
        for (int j = 0; j < m; ++j) {
          int v = dp[j];
          dp[j] = pre;
          pre += v;
          if (pre >= MOD)
            pre -= MOD;
        }
      } else {
        int suf = 0;
        for (int j = m - 1; j >= 0; --j) {
          int v = dp[j];
          dp[j] = suf;
          suf += v;
          if (suf >= MOD)
            suf -= MOD;
        }
      }
    }
    long long res = 0;
    for (int j = 0; j < m; ++j) {
      res += dp[j];
      if (res >= MOD)
        res -= MOD;
    }
    res *= 2;
    if (res >= MOD)
      res -= MOD;
    return (int)res;
  }
};
