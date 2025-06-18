class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<long long> pref;
        pref.push_back(0);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                pref.push_back(pref.back() + i);
            }
        }
        n = static_cast<int>(pref.size()) - 1;
        int m = max(0, k - maxChanges);
        long long ans = 1e12;
        for (int l = m; l <= min(n, min(m + 3, k)); ++l) {
            for (int i = 0; i <= n - l; ++i) {
                int lm = i + l / 2;
                int rm = i +l - l / 2;
                long long cur = pref[i + l] - (pref[lm] - pref[i]) - pref[rm];
                ans = min(ans, cur + (k - l) * 2);
            }
        }
        return ans;
    }
};
