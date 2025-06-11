class Solution {
public:
    string lexicographicallySmallestString(string s) {
        static const int maxn = 251;
        static bool f[maxn][maxn];
        int n = s.size();
        auto chk = [&](int u, int v) -> bool {
            int dt = abs(u - v);
            return min(dt, 26 - dt) == 1;
        };
        for(int i = 1; i < n; ++i)
            f[i - 1][i] = chk(s[i - 1] - 'a', s[i] - 'a');
        for(int len = 4; len <= n; len += 2)
            for(int L = 0, R = len - 1; R < n; ++L, ++R) {
                f[L][R] = 0;
                if(f[L + 1][R - 1] && chk(s[L] - 'a', s[R] - 'a')) {
                    f[L][R] = 1;
                    continue;
                }
                for(int M = L + 2; M < R; M += 2)
                    if(f[L][M - 1] && f[M][R]) {
                        f[L][R] = 1;
                        break;
                    }
            }
        string ans = "";
        vector<int> cur = {0}, nxt;
        for(int i = 0; i < n; ++i) {
            char best = 'z';
            for(int L: cur) {
                if(!((n - L) & 1) && (L >= n || f[L][n - 1]))
                    return ans;
                for(int R = L; R < n; R += 2) {
                    if((L < R && !f[L][R - 1]) || s[R] > best)
                        continue;
                    if(s[R] < best) {
                        best = s[R];
                        nxt.clear();
                    }
                    nxt.push_back(R + 1);
                }
            }
            sort(nxt.begin(), nxt.end());
            nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
            cur.clear();
            cur.swap(nxt);
            ans.push_back(best);
        }
        return ans;
    }
};
