int dp[1'000'000 + 100'011];
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) { return a[0] < b[0]; });
        const int n = events.size();
        #define DP(a, b) dp[(a) * (n + 1) + (b)]
        memset(dp, 0, sizeof(int) * (n + 1));
        for (int i = 1; i <= k; i++) DP(i, n) = 0;
        for (int cur = n - 1; cur >= 0; cur--) {
            auto nxt = upper_bound(events.begin() + cur, events.end(), events[cur][1],
                [](int t, const auto& a) { return t < a[0]; }
            ) - events.begin();
            for (int cnt = 1; cnt <= k; cnt++) {
                DP(cnt, cur) = max(DP(cnt, cur + 1), events[cur][2] + DP(cnt - 1, nxt));
            }
        }
        return DP(k, 0);
    }
};
