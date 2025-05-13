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
#define pb push_back
#define MOD 1000000007
#define epsilon 1e-7
class Solution {
public:
  double solveDis(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  }

  pair<double, double> solve(vvi &positions,int n) {
    double xC = 0.0, yV = 0.0;
    for (auto &i : positions) {
      xC += i[0];
      yV += i[1];
    }
    xC /= n;
    yV /= n;
    for (int i = 0; i < 1000; i++) {
      double numX = 0.0, numY = 0.0, deno = 0.0;
      int sameP = 1;
      for (auto &p : positions) {
        double dist = solveDis(xC, yV, p[0], p[1]);
        if (dist > epsilon) {
          numX += p[0] / dist;
          numY += p[1] / dist;
          deno += 1.0 / dist;
          sameP = 0;
        } else {
          numX += p[0];
          numY += p[1];
          deno += 1.0;
        }
      }
      if (sameP)
        return {xC, yV};
      if (abs(deno) < epsilon) {
        return {xC, yV};
      }
      double newXc = numX / deno;
      double newXy = numY / deno;
      if (solveDis(xC, yV, newXc, newXy) < epsilon) {
        return {newXc, newXy};
      }
      xC = newXc;
      yV = newXy;
    }
    return {xC, yV};
  }
  double getMinDistSum(vector<vector<int>> &positions) {
    int n = positions.size();
    if (n == 0) return 0.0;
    auto [xC, yV] = solve(positions,n);
    double ans = 0.0;
    for (auto &i : positions) {
      ans += solveDis(xC, yV, i[0], i[1]);
    }
    return ans;
  }
};
