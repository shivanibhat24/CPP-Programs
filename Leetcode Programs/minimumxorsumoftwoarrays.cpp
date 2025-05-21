class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(1<<nums2.size(), INT_MAX);
        dp[0] = 0;
        for(size_t mask = 0; mask < dp.size(); ++mask ) {
            int nums1Idx = popcount(mask);
            for(int i=0; i<nums1.size(); ++i) {
                if (mask & (1<<i)) {
                    continue;
                }
                int newMask = mask + (1<<i);
                dp[newMask] = min(dp[newMask], dp[mask] + (nums1[nums1Idx] ^ nums2[i]));
            }
        }
        return dp.back();
    }
private:
    int minimumXorSumDfs(const vector<int>& nums1, const vector<int>& nums2, vector<int>& nums2Idx, vector<int>& cache, int usedMask, int idx)
    {
        if (idx == nums1.size() - 1) {
            return nums1.back() ^ nums2[nums2Idx.back()];
        }
        if (cache[usedMask] != INT_MAX) {
            return cache[usedMask];
        }
        int minValue = INT_MAX;
        for(size_t i=idx; i<nums2.size(); ++i) {
            swap(nums2Idx[idx], nums2Idx[i]);
            int newUsedMask = usedMask +  (1 << nums2Idx[idx]);
            int localValue = (nums1[idx] ^ nums2[nums2Idx[idx]]) + minimumXorSumDfs(nums1, nums2, nums2Idx, cache, newUsedMask, idx+1);
            minValue = min(localValue, minValue);
            swap(nums2Idx[idx], nums2Idx[i]);
        }
        return cache[usedMask] = minValue;
    }
};
