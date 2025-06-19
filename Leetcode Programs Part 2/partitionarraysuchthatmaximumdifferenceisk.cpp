class Solution {
public:
  int partitionArray(vector<int>& nums, int k) {
    auto [min_num, max_num] = ranges::minmax(nums);
    auto seen = bitset<100'001>{};
    for (auto num : nums) seen.set(num - min_num);
    auto n = max_num - min_num + 1;
    auto num_partitions = 0;
    for (auto i = 0; i < n;) {
      num_partitions += 1;
      auto next_i = i + k + 1;
      for (; next_i < n && !seen[next_i]; ++next_i);
      i = next_i;
    }
    return num_partitions;
  }
};
