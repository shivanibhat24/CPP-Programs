class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int even = 0, odd = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) even += nums[i];
            else odd += nums[i];
        }

        int pref_even = 0, pref_odd = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int new_even, new_odd;

            if (i % 2 == 0) {
                new_even = pref_even + (odd - pref_odd);
                new_odd  = pref_odd + (even - pref_even - nums[i]);
            } else {
                new_even = pref_even + (odd - pref_odd - nums[i]);
                new_odd  = pref_odd + (even - pref_even);
            }

            if (new_even == new_odd) ans++;

            if (i % 2 == 0) pref_even += nums[i];
            else pref_odd += nums[i];
        }

        return ans;
    }
};
