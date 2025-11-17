class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = (int)nums.size();        
        vector<int> stableR;
        stableR.push_back(-1);
        for (int i = 0; i + 1 < n; i++)
            if (nums[i] > nums[i + 1])
                stableR.push_back(i);
        stableR.push_back(n - 1);
        const int m = (int)stableR.size();
        vector<long long> blockPartialCount(m, 0);
        for (int i = 1; i < m; i++) {
            const int len = stableR[i] - stableR[i - 1];
            blockPartialCount[i] = 1LL * len * (len + 1) / 2 + blockPartialCount[i - 1];
        }
        vector<int> blockID(n, INT_MAX);
        for (int i = 1; i < (int)stableR.size(); i++)
            blockID[stableR[i]] = i;
        for (int i = n - 2; i >= 0; i--)
            blockID[i] = min(blockID[i], blockID[i + 1]);
        vector<long long> ans;
        for (auto& query : queries) {
            const int l = query[0];
            const int r = query[1];
            const int blockL = blockID[l];
            const int blockR = blockID[r];
            long long stableCount = 0;
            if (blockL == blockR) {
                const int len = r - l + 1;
                stableCount = 1LL * len * (len + 1) / 2;
            }
            else {
                stableCount += blockPartialCount[blockR - 1] - blockPartialCount[blockL];                
                const int lenL = stableR[blockL] - l + 1;
                const int lenR = r - stableR[blockR - 1];
                stableCount += 1LL * lenL * (lenL + 1) / 2;
                stableCount += 1LL * lenR * (lenR + 1) / 2;
            }
            ans.push_back(stableCount);
        }
        return ans;
    }
};
