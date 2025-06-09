class Solution {
public:
    int countTriplets(vector<int>& nums) {
        constexpr int MAX_BITS = 16, MAX_VAL = (1 << MAX_BITS) - 1;
        vector<int> cnt(MAX_VAL + 1);
        const int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            cnt[nums[i]]++;
            for (int j = i + 1; j < n; ++j)
                cnt[nums[i] & nums[j]] += 2;
        }
        for (int i = 0; i < MAX_BITS; ++i) {
            for (int mask = 0; mask <= MAX_VAL; ++mask) {
                if (mask & (1 << i)) 
                    cnt[mask] += cnt[mask ^ (1 << i)];
            }
        }
        int ans = 0;
        for (const int val : nums) 
            ans += cnt[MAX_VAL ^ val];
        return ans;
    }
};
