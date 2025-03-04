class Solution {
   public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		array<array<int, 105>, 105> dp;
		for (auto& row : dp) {
			row.fill(-1);
		}
		dp[0][0] = 0;

		for (string& s : strs) {
			int one = 0, zero = 0;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == '1') ++one;
				else ++zero;
			}

			for (int i = m; i >= 0; --i) {
				for (int j = n; j >= 0; --j) {
					if (dp[i][j] != -1) {
						int I = i + zero, J = j + one;
						if (I <= m && J <= n) {
							if (dp[I][J] == -1) dp[I][J] = dp[i][j] + 1;
							else dp[I][J] = max(dp[I][J], dp[i][j] + 1);
						}
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) ans = max(ans, dp[i][j]);
		}

		return ans;
	}
};
