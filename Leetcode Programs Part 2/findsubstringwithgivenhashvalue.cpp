class Solution {
public:
  string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    int n = s.size();
    long long hashSum = 0, pk = 1;
    int ans = 0;
    for (int i = n - 1; i >= n - k; --i) {
      hashSum = (hashSum * power + (s[i] - 'a' + 1)) % modulo;
      pk = pk * power % modulo;
    }
    if (hashSum == hashValue) {
      ans = n - k;
    }
    for (int i = n - k - 1; i >= 0; --i) {
      hashSum =
          ((hashSum * power + (s[i] - 'a' + 1) - (s[i + k] - 'a' + 1) * pk) %
               modulo +
           modulo) %
          modulo;
      if (hashSum == hashValue) {
        ans = i;
      }
    }
    return s.substr(ans, k);
  }
};
