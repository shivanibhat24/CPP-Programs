class Solution {
 public:
  vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
    int mx = *max_element(nums.begin(), nums.end());
    vector<int> f(mx + 1);
    vector<long long> gcd(mx + 1);  
    for (int x : nums) f[x]++;
    for (int i = mx; i > 0; --i) {
      long long cnt = 0, rep = 0;
      for (int j = i; j <= mx; j += i) {
        cnt += f[j];
        rep += gcd[j];
      }
      gcd[i] = (cnt * (cnt - 1) / 2) - rep;
    }
    for (int i = 1; i <= mx; ++i) gcd[i] += gcd[i - 1];
    vector<int> res;
    for (long long q : queries) {
      int l = 1, r = mx + 1;
      while (l < r) {
        int m = (l + r) >> 1;
        if (gcd[m] <= q) l = m + 1;
        else r = m;
      }
      res.push_back(l);
    }
    return res;
  }
};
