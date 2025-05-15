class Solution {
public:
    int stoneGameV(vector<int> & vals) {
        const auto n = vals.size();
        vector lhs   = vector(n, vector<long long>(n));
        vector<long long> rhs(n);
        long long sum{};
        lhs[0][0] = vals[0];
        for (size_t r = 1; r < n; ++r) {
            lhs[r][r] = sum = vals[r];
            long long rsum{}, mxr{};
            fill(rhs.begin(), rhs.end(), 0);
            rhs[r] = vals[r];
            for (int l = r - 1, m = r + 1; l >= 0; --l) {
                sum += vals[l];
                while (l + 1 < m && (rsum + vals[m - 1]) << 1 <= sum) {
                    rsum += vals[--m];
                    mxr = max(mxr, rhs[m]);
                }
                auto lsum      = sum - rsum;
                const auto lo  = 2 - (lsum == rsum);
                const auto mxl = l <= m - lo ? lhs[l][m - lo] : 0;
                rhs[l]         = max(rhs[l], sum + max(mxl, mxr));
                lhs[l][r]      = max(lhs[l][r - 1], rhs[l]);
            }
        }
        return rhs[0] - sum;
    }
};
