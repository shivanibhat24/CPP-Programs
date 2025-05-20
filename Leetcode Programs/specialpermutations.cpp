class Solution {
public:
    vector<int> G[14];
    int DP[1 << 14][14], mod = 1000000007;
    int solve(int visited, int v) {
        if (DP[visited][v] == -1) {
            int submask = visited & ~(1 << v);
            if (submask == 0)
                DP[visited][v] = 1;
            else {
                DP[visited][v] = 0;
                for (int ady : G[v])
                    if (submask & (1 << ady))
                        DP[visited][v] = (DP[visited][v] + solve(submask, ady)) % mod;
            }
        }
        return DP[visited][v];
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (max(nums[i], nums[j]) % min(nums[i], nums[j]) == 0) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
        memset(DP, -1, sizeof DP);
        int result = 0;
        for (int i = 0; i < n; ++i)
            result = (result + solve((1 << n) - 1, i)) % mod;
        return result;
    }
};
