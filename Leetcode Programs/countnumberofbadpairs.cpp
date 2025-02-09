#include <ranges>
class Solution {
public:
  long long countBadPairs(vector<int>& nums) {
    auto n = size(nums);
    long long num_bad_pairs = (n * (n - 1)) >> 1;
    for (auto [i, num] : nums | views::enumerate) num -= i;
    sort(begin(nums), end(nums));
    for (auto chunk : nums | views::chunk_by(equal_to{})) {
      auto m = size(chunk);
      num_bad_pairs -= (m* (m - 1)) >> 1;
    }
     return num_bad_pairs;
  }
};
