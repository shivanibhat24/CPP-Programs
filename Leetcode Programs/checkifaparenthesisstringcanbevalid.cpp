class Solution {
public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    if ((n&1) == 1)
      return false;
    int min = 0, max = 0;
    for (int i = 0; i < n; ++i) {
      if (locked[i] == '1') {
        if (s[i] == '(') {
          ++min;
          ++max;
        } else {
          --min;
          --max;
        }
      } else {
        --min;
        ++max;
      }
      if (max < 0) 
        return false;      
      if (min < 0) 
        min = 0;
    }
    return min == 0;
  }
};
