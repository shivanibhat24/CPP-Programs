static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

static inline bool is_vowel(char c) {
  return c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution {
public:
  static long long countOfSubstrings(const string& word, int k) {
    auto num_substrings = 0ll;
    auto vowel_counts = array<int, 26>{};
    auto cons_count = 0;
    auto unique_vowel_count = 0;
    int n = size(word);
    for (auto l = 0, r_inner = 0, r_outer = 0; r_outer < n; ) {
      for (;
           r_inner < n && (cons_count < k || (unique_vowel_count < 5 &&
                                              is_vowel(word[r_inner])));
           ++r_inner) {
        if (auto c = word[r_inner]; is_vowel(c)) {
          if (vowel_counts[c - 'a']++ == 0)  ++unique_vowel_count;
        } else {
          ++cons_count;
        }
      }
      for (r_outer = r_inner;
           r_outer < n && is_vowel(word[r_outer]);
           ++r_outer);
      for (; l < r_outer && cons_count == k; ++l) {
        for (; r_inner < r_outer && unique_vowel_count < 5; ++r_inner) {
          if (vowel_counts[word[r_inner] - 'a']++ == 0) ++unique_vowel_count;
        }
        
        if (unique_vowel_count == 5) num_substrings += (r_outer - r_inner) + 1;

        if (auto c = word[l]; is_vowel(c)) {
          if (--vowel_counts[c - 'a'] == 0) --unique_vowel_count;
        } else {
          --cons_count;
        }
      }
      
      if (!k && l == r_outer && r_outer < n) {
        ++l;
        ++r_inner;
        ++r_outer;
      }
    }
    return num_substrings;
  }
};
