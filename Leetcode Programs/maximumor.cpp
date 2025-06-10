class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        int pref[n + 1], suff[n + 1];
        pref[0] = 0, suff[n] = 0;
        for (int i = 0; i < n; ++i)
            pref[i + 1] = (pref[i] | nums[i]), suff[n - i - 1] = (suff[n - i] | nums[n - i - 1]);
        long long res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, pref[i] | suff[i + 1] | ((long long)nums[i] << k));
        return res;
    }
};
