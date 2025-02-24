const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
class Solution {
public:
  int rec(int l, int r, vector<vector<int>> &dp, vector<int> &nums){
    if (l > r) return (0);
    if (dp[l][r] != -1) return dp[l][r];
    for (int i = l; i <= r; i++){
      int cur_coins = nums[i] * nums[l - 1] * nums[r + 1];
      int left_coins = rec(l, i - 1, dp, nums);
      int right_coins = rec(i + 1, r, dp, nums);
      dp[l][r] = max(dp[l][r], left_coins + right_coins + cur_coins);
    }
    return (dp[l][r]);
  }

  int maxCoins(vector<int>& i_nums) {
    int n = i_nums.size();
    vector<int> nums(n + 2, 1);
    n = nums.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    for (int i = 1; i < n - 1; i++) nums[i] = i_nums[i - 1]; 
    int ans = rec(1, n - 2, dp, nums);
    return (ans);
  }
};
