class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m1 = 0;
        int m2 = 0;
        int totalSum1 = 0;
        int totalSum2 = 0;
        for(int i = 0; i < n; i ++) {
            totalSum1 += nums1[i];
            totalSum2 += nums2[i];
        }
        for (int i = 0; i < n; i ++) {
            int diff1 = nums2[i] - nums1[i];
            // cout << diff1  << endl;
            m1 = max(max( diff1, m1 + diff1), 0);
            m2 = max(max(-diff1, m2 - diff1), 0);
            ans = max({
                ans,
                totalSum1 + m1,
                totalSum2 + m2,
            });
        }
        return ans;
    }
};
