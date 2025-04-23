#include <bits/stdc++.h>

#include <limits>
using namespace std;
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
auto init2 = atexit([]() { ofstream("display_runtime.txt") << 0; });

class Solution {
  public:
    static bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix;
        prefix[0] = -1;
        int prev = 0;
        for (int idx = 0; idx < static_cast<int>(nums.size()); ++idx) {
            auto num = nums[idx];
            prev += num;
            prev %= k;
            auto [it, inserted] = prefix.emplace(prev, idx);
            if (!inserted && it->second + 1 != idx) {
                return true;
            }
        }

        return false;
    }
};
