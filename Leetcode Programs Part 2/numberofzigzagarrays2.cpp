class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        typedef long long LL;
        static const int maxn = 75, mod = (int)1e9 + 7;
        static int f[3][maxn][maxn], A = 0, B = 1, C = 2; 
        auto modInc = [&](int &x, int y) {
            (x += y) >= mod && (x -= mod);
        };
        auto modIncMul = [&](int &x, int y, int z) {
            assert(y);
            z && (x = (x + (LL)y * z) % mod);
        };
        int m = r - l + 1;
        --n;
        if(n & 1) {
            for(int i = 0; i < m; ++i)
                f[A][0][i] = m - 1 - i;
        } else {
            for(int i = 0; i < m; ++i)
                f[A][0][i] = 1;
        }
        for(int i = 1; i < m; ++i)
            memset(f[A][i], 0, m * sizeof(int));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < m; ++j)
                f[B][i][j] = m - 1 - max(i, j);
        n >>= 1;
        assert(n > 0);
        while(1) {
            if(n & 1) {
                memset(f[C][0], 0, m * sizeof(int));
                for(int i = 0; i < m; ++i) if(f[A][0][i])
                    for(int j = 0; j < m; ++j)
                        modIncMul(f[C][0][j], f[A][0][i], f[B][i][j]);
                swap(A, C);
            }
            n >>= 1;
            if(!n)
                break;
            for(int i = 0; i < m; ++i) {
                memset(f[C][i], 0, m * sizeof(int));
                for(int j = 0; j < m; ++j) if(f[B][i][j])
                    for(int k = 0; k < m; ++k)
                        modIncMul(f[C][i][k], f[B][i][j], f[B][j][k]);
            }
            swap(B, C);
        }
        int ans = 0;
        for(int i = 0; i < m; ++i)
            modInc(ans, f[A][0][i]);
        modInc(ans, ans);
        return ans;
    }
};
