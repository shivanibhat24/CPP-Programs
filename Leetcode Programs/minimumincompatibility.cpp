class Solution {
public:
    const int MAX = INT_MAX / 2;
    int dfs(std::vector<int> &nums, int k, int n, int prev, int mask, int subsetSize, std::vector<std::vector<int>> &dpTable) {
        if (mask == 0) {
            return 0;
        }
        if (__builtin_popcount(mask) % subsetSize == 0) {
            int idx = -1;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    idx = i;
                    break;
                }
            }
            return dfs(nums, k, n, idx, mask ^ (1 << idx), subsetSize, dpTable);
        }
        if  (dpTable[prev][mask] != -1) return dpTable[prev][mask];
        int result = MAX;
        for (int next = prev + 1; next < n; ++next) {
            if ((mask & (1 << next)) && (nums[next] != nums[prev])) {
                result = std::min(result, nums[next] - nums[prev] + dfs(nums, k, n, next, mask ^ (1 << next), subsetSize, dpTable));
            }
        }
        return dpTable[prev][mask] = result;
    }
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        std::unordered_map<int, int> freqCount;
        for (auto &num : nums) {
            freqCount[num]++;
            if (freqCount[num] > k) return -1;
        }
        int subsetSize = n / k;
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> dpTable(n, std::vector<int>(1 << n, -1));
        return dfs(nums, k, n, 0, (1 << n) - 1, subsetSize, dpTable);
    }
};
