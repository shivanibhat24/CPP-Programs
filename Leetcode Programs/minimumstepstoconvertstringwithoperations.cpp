class Solution {
public:
    int f[2][105][105], g[105];
    int minOperations(string a, string b) {
        int i, j, k, w, n = a.size(), T = 0, x, y;
        int cnt[26][26], sj[26][26];
        for (i = 0; i < 26; ++i)
            for (j = 0; j < 26; ++j)
                cnt[i][j] = sj[i][j] = 0;
        for (i = 0; i < n; ++i)
            for (j = i; j < n; ++j)
                for (w = 0; w < 2; ++w){
                    if (w == 1) reverse(a.begin() + i, a.begin() + j + 1);
                    f[w][i][j] = w;
                    ++T;
                    for (k = i; k <= j; ++k)
                        if (a[k] != b[k]){
                            ++f[w][i][j];
                            x = a[k] - 'a'; y = b[k] - 'a';
                            if (sj[y][x] == T && cnt[y][x] > 0){
                                --cnt[y][x];
                                --f[w][i][j];
                            }
                            else{
                                if (sj[x][y] < T){
                                    sj[x][y] = T;
                                    cnt[x][y] = 0;
                                }
                                ++cnt[x][y];
                            }
                        }
                    if (w == 1) reverse(a.begin() + i, a.begin() + j + 1);
                }
        g[0] = 0;
        for (i = 1; i <= n; ++i){
            g[i] = 1000000000;
            for (j = 1; j <= i; ++j) g[i] = min(g[i], g[j - 1] + min(f[0][j - 1][i - 1], f[1][j - 1][i - 1]));
        }
        return g[n];
    }
};
