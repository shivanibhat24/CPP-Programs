class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v(10001, 0);
        int l = INT_MAX, n = 0;
        for (auto &a: grid) for (int b: a) {
            l = min(l, b);
            v[b]++;
            n++;
        }
        long c = 0;
        for (int i = 0; i <= 10000; i++) {
            if (v[i] > 0) {
                if ((i - l) % x != 0) return -1;
                c += (i - l) * v[i] / x;
            }
        }
        long m = c, ans = c, k = 0;
        for (int i = 1; i ; i++) {
            k += v[l + (i - 1) * x];
            m += (2 * k - n);
            ans = min(ans, m);
            if (2 * k - n > 0) return ans;
        }
        return ans;
    }
};
