class Solution {
private:
    typedef unsigned short dim_t;
    static constexpr unsigned MAXV = 1000000u;
    static constexpr unsigned FSIZE = MAXV + 1u;
    static dim_t freqs[FSIZE];
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        const dim_t n = matrix.size();
        const dim_t m = matrix[0].size();
        unsigned minv = matrix[0][0], maxv = minv;
        freqs[maxv]++;
        for (dim_t i = 1; i < n; i++) {
            const unsigned v = matrix[i][0] ^= matrix[i - 1][0];
            if (minv > v) minv = v;
            if (maxv < v) maxv = v;
            freqs[v]++;
        }
        for (dim_t j = 1; j < m; j++) {
            const unsigned v = matrix[0][j] ^= matrix[0][j - 1];
            if (minv > v) minv = v;
            if (maxv < v) maxv = v;
            freqs[v]++;
        }
        for (dim_t i = 1; i < n; i++)
            for (dim_t j = 1; j < m; j++) {
                const unsigned v = matrix[i][j] ^= matrix[i][j - 1] ^ matrix[i - 1][j] ^ matrix[i - 1][j - 1];
                if (minv > v) minv = v;
                if (maxv < v) maxv = v;
                freqs[v]++;
            }
        unsigned v = maxv;
        for (unsigned count = 0; count < k; v--)
            count += freqs[v];
        fill(freqs + minv, freqs + maxv + 1u, 0);
        return v + 1u;
    }
};
Solution::dim_t Solution::freqs[FSIZE];
