#include <ranges>

// static auto init = []() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);
  // return nullptr;
// }();

class Solution {
public:
  long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    auto indexes = vector<ssize_t>{-1};
    for (auto [i, num] : views::enumerate(nums)) {
      if (num % modulo == k) indexes.push_back(i);
    }
    indexes.push_back(size(nums));

    auto min_interesting_in_window = k ? k : modulo;
    auto augmented_windows = views::slide(indexes, min_interesting_in_window + 2);
    auto num_left_indexes_per_cycle = vector<int>(
        min(static_cast<size_t>(modulo), size(augmented_windows)));
    auto ans = 0ll;
    for (auto [i, window] : views::enumerate(augmented_windows)) {
      auto cycle = i % modulo;
      auto num_left_indexes =
          (num_left_indexes_per_cycle[cycle] += window[1] - window[0]);
      auto num_right_indexes = window[size(window) - 1] -
          window[size(window) - 2];
      ans += num_left_indexes * num_right_indexes;
    }

    if (!k) {
      for (auto [a, b] : views::pairwise(indexes)) {
        auto indexes_between = b - a  - 1;
        ans += ((indexes_between + 1) * indexes_between) >> 1;
      }
    }
    return ans;
  }
};
