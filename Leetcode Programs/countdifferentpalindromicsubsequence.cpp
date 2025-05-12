class Solution
{
public:
   int countPalindromicSubsequences(string s)
   {
      int n = s.size();
      const int mod = 1e9 + 7;
      vector<int> prev(n, -1), next(n, n);
      unordered_map<char, int> mp;
      for (int i = 0; i < n; i++)
      {
         if (mp.count(s[i]))
            prev[i] = mp[s[i]];
         mp[s[i]] = i;
      }
      mp.clear();
      for (int i = n - 1; i >= 0; i--)
      {
         if (mp.count(s[i]))
            next[i] = mp[s[i]];
         mp[s[i]] = i;
      }

      int dp[n][n];
      memset(dp, 0, sizeof(dp));
      for (int g = 0; g < n; g++)
      {
         for (int i = 0, j = g; j < n; i++, j++)
         {
            if (g == 0)
            {
               dp[i][j] = 1;
            }
            else if (g == 1)
            {
               dp[i][j] = 2;
            }
            else
            {
               if (s[i] == s[j])
               {
                  int nextidx = next[i];
                  int previdx = prev[j];
                  if (nextidx > previdx)
                  {
                     dp[i][j] = ((2 * dp[i + 1][j - 1]) + 2) % mod;
                  }
                  else if (nextidx == previdx)
                  {
                     dp[i][j] = ((2 * dp[i + 1][j - 1]) + 1) % mod;
                  }
                  else
                  {
                     dp[i][j] = ((2 * dp[i + 1][j - 1]) % mod - dp[nextidx + 1][previdx - 1]) % mod;
                  }
               }
               else
               {
                  dp[i][j] = ((dp[i][j - 1] + dp[i + 1][j]) % mod - dp[i + 1][j - 1]) % mod;
               }
            }
         }
      }
      if (dp[0][n - 1] < 0)
         dp[0][n - 1] += mod;
      return dp[0][n - 1];
   }
};
