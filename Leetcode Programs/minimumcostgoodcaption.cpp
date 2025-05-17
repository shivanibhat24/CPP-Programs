class Solution {
    public:
        string minCostGoodCaption(string s) {
            int n = s.size();
            if (n < 3) {
                return "";
            }    
            vector<int> f(n + 1);
            f[n - 1] = f[n - 2] = INT_MAX / 2;
            vector<char> t(n + 1);
            vector<uint8_t> size(n);    
            for (int i = n - 3; i >= 0; i--) {
                string sub = s.substr(i, 3);
                ranges::sort(sub);
                char a = sub[0], b = sub[1], c = sub[2];
                char s3 = t[i + 3];
                int res = f[i + 3] + (c - a);
                int mask = b << 24 | s3 << 16 | s3 << 8 | s3;
                size[i] = 3;    
                if (i + 4 <= n) {
                    string sub = s.substr(i, 4);
                    ranges::sort(sub);
                    char a = sub[0], b = sub[1], c = sub[2], d = sub[3];
                    char s4 = t[i + 4];
                    int res4 = f[i + 4] + (c - a + d - b);
                    int mask4 = b << 24 | b << 16 | s4 << 8 | s4;
                    if (res4 < res || res4 == res && mask4 < mask) {
                        res = res4;
                        mask = mask4;
                        size[i] = 4;
                    }
                }    
                if (i + 5 <= n) {
                    string sub = s.substr(i, 5);
                    ranges::sort(sub);
                    char a = sub[0], b = sub[1], c = sub[2], d = sub[3], e = sub[4];
                    int res5 = f[i + 5] + (d - a + e - b);
                    int mask5 = c << 24 | c << 16 | c << 8 | t[i + 5];
                    if (res5 < res || res5 == res && mask5 < mask) {
                        res = res5;
                        mask = mask5;
                        size[i] = 5;
                    }
                }    
                f[i] = res;
                t[i] = mask >> 24;
            }    
            string ans;
            for (int i = 0; i < n; i += size[i]) {
                ans.append(size[i], t[i]);
            }
            return ans;
        }
    };
    
