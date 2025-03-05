class Solution {
   public:
	static int longestArithSeqLength(vector<int>& nums) {
		const int max_val = *max_element(nums.begin(), nums.end());
		int max_len = 0;
		for (int d = 0; d <= max_val; d = (d <= 0) ? 1 - d : -d) {
			if (d != 0 && (max_val / abs(d)) + 1 <= max_len) break;
			vector<int> dp(max_val + 1);
			for (const int n : nums) {
				const int prev = n - d;
				dp[n] = (prev >= 0 && prev <= max_val) ? dp[prev] + 1 : 1;
				max_len = max(max_len, dp[n]);
			}
		}
		return max_len;
	}
};
