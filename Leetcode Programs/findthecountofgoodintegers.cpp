#include <ranges>

template<size_t N>
constexpr auto make_fact() {
  auto fact = array<long long, N>{1, 1};
  for (auto i : views::iota(2u, N)) fact[i] = i * fact[i - 1];
  return fact;
}

constexpr auto fact = make_fact<11>();

long long make_perm_index(int n, int k, const array<int, 10>& digit_counts) {
  long long perm_index =  n | (k << 4);
  for (auto [i, digit_count] : views::enumerate(digit_counts)) {
    perm_index |= static_cast<long long>(digit_count) << (4 * (i + 2));
  }
  return perm_index;
}

void count_palindrome_perms(
    string& prefix,
    array<array<long long, 10>, 11>& solutions,
    unordered_set<long long>& seen_perms) {
  if (empty(prefix)) {
    for (auto i : views::iota('1', '9' + 1)) {
      prefix.push_back(i);
      count_palindrome_perms(prefix, solutions, seen_perms);
      prefix.pop_back();
    }
  } else {
    for (auto suffix_trim : views::iota(0, 2)) {
      auto suffix = prefix.substr(0, size(prefix) - suffix_trim);
      ranges::reverse(suffix);
      auto palindrome = prefix + suffix;

      auto digit_counts = array<int, 10>{};
      for (auto digit : palindrome) ++digit_counts[digit - '0'];

      int n = ssize(palindrome);
      auto num_perms = fact[n];
      for (auto digit_count : digit_counts) {
        if (digit_count > 1) num_perms /= fact[digit_count];
      }
      if (digit_counts[0]) {
        // cout << "palindrome: " << palindrome << " num_perms (leading zeros included): " << num_perms;
        num_perms -= (num_perms * digit_counts[0] / n);
        // cout << " num_perms (exlcuding leading zeros): " << num_perms << '\n';
      }
      
      auto palindrome_val = stoll(palindrome);
      // if (n == 4 && palindrome_val % 1 == 0) {
        // cout << "palindrome: " << palindrome << " num_perms: " << num_perms;
        // if (seen_perms.contains(make_perm_index(4, 1, digit_counts))) {
          // cout << " (repeat!)";
        // }
        // cout << '\n';
      // }
      for (auto k : views::iota(1, 10)) {
        auto perm_index = make_perm_index(n, k, digit_counts);
        if (palindrome_val % k == 0 && !seen_perms.contains(perm_index)) {
          solutions[n][k] += num_perms;
          seen_perms.insert(perm_index);
        }
      }
    }
    if (size(prefix) < 5) {
      for (auto i : views::iota('0', '9' + 1)) {
        prefix.push_back(i);
        count_palindrome_perms(prefix, solutions, seen_perms);
        prefix.pop_back();
      }
    }
  }
}

const array<array<long long, 10>, 11> solve_for_all() {
  auto solutions = array<array<long long, 10>, 11>{};
  auto seen_perms = unordered_set<long long>{};
  auto prefix = ""s;
  count_palindrome_perms(prefix, solutions, seen_perms);
  return solutions;
}

const array<array<long long, 10>, 11> solutions = solve_for_all();

class Solution {
public:
  long long countGoodIntegers(int n, int k) {
    return solutions[n][k];
  }
};
