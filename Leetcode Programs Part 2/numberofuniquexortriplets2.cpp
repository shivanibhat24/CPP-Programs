class Solution {
public:
    void help(vector<long long>& a, bool inverse) {
        int n = a.size();
        for (int h = 1; h < n; h <<= 1) {
            for (int i = 0; i < n; i += h * 2) {
                for (int j = 0; j < h; ++j) {
                    long long x = a[i + j];
                    long long y = a[i + j + h];
                    a[i + j] = x + y;
                    a[i + j + h] = x - y;
                }
            }
        }
        if (inverse) {
            for (int i = 0; i < n; ++i) {
                a[i] = round((double)a[i] / n);
            }
        }
    }
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        if (set.empty()) return 0;
        int maxVal = *max_element(set.begin(), set.end());
        int m = 0;
        while ((1 << m) <= maxVal) m++;
        int L = 1 << m;
        vector<long long> f(L, 0);
        for (int x : set) {
            f[x] = 1;
        }
        help(f, false);
        for (int i = 0; i < L; ++i) {
            f[i] = f[i] * f[i] * f[i];
        }
        help(f, true);
        int count = 0;
        for (long long x : f) {
            if (x > 0) count++;
        }
        return count;
    }
};
