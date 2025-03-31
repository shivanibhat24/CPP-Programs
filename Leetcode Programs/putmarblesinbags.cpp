
class Solution {
public:
    long long putMarbles(vector<int> &wt, int k) {
        if (--k == 0) return 0;
        int n = wt.size() - 1;
        for (int i = 0; i < n; ++i)
            wt[i] += wt[i + 1];
        wt.pop_back();
        long ans = 0;
        nth_element(wt.begin(), wt.begin() + k, wt.end());
        for (int i = 0; i < k; ++i)
            ans -= wt[i];
        nth_element(wt.begin(), wt.end() - k, wt.end());
        for (int i = 0; i < k; ++i)
            ans += wt[n - 1 - i];
        return ans;
    }
};
