using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using umii = unordered_map<int, int>;
#define pb push_back
#define MOD 1000000007
class Solution {
public:
  int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight) {
    int n = boxes.size();
    vi dp(n + 1, n * 2);
    dp[0] = 0;
    int curr = 0, w = 0, b = 0, s = 0, e = 0;
    for (int i = 0; i < n; ++i) {
      while (e < n && b < maxBoxes && w + boxes[e][1] <= maxWeight) {
        b++;
        w += boxes[e][1];
        if (e == 0 || boxes[e][0] != boxes[e - 1][0]) {
          curr++;
          s = e;
        }
        e++;
      }
      dp[e] = min(dp[e], dp[i] + curr + 1);
      dp[s] = min(dp[s], dp[i] + curr);
      if (i == n - 1 || boxes[i][0] != boxes[i + 1][0]) {
        curr--;
      }
      b--;
      w -= boxes[i][1];
    }
    return dp[n];
  }
};
