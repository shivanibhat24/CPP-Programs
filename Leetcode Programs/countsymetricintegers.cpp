#include <ranges> 

constexpr bool is_symmetric(int x) {
  int num_digits;
  if (10 <= x && x < 100) num_digits = 2;
  else if (1'000 <= x && x < 10'000) num_digits = 4;
  else return false;

  auto low_sum = 0;
  for (auto _ : views::iota(0, num_digits >> 1)) {
    low_sum += x % 10;
    x /= 10;
  }
  auto high_sum = 0;
  for (auto _ : views::iota(0, num_digits >> 1)) {
    high_sum += x % 10;
    x /= 10;
  }
  return low_sum == high_sum;
}

constexpr array<int, 10'002> make_symmetric_counts() {
  auto symmetric_counts = array<int, 10'002>{};
  auto prefix_count = 0;
  for (auto i : views::iota(11, 100)) {
    if (is_symmetric(i)) ++prefix_count;
    symmetric_counts[i + 1] = prefix_count;
  }
  fill(begin(symmetric_counts) + 100, begin(symmetric_counts) + 1001, prefix_count);
  for (auto i : views::iota(1001, 10'000)) {
    if (is_symmetric(i)) ++prefix_count;
    symmetric_counts[i + 1] = prefix_count;
  }
  symmetric_counts[10'000] = prefix_count;
  symmetric_counts[10'001] = prefix_count;
  return symmetric_counts;
}

constexpr array<int, 10'002> symmetric_counts = make_symmetric_counts();

class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    return symmetric_counts[high + 1] - symmetric_counts[low];
  }
};
