class Solution {
public:
    bool check(string& a, string& b) {
        if(a.size() != b.size())
            return false;
        int cnt = 0;
        for(int i = 0; i < a.size(); ++i) {
            cnt += (a[i] != b[i]);
            if(cnt > 1) return false;
        }
        return cnt == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n = words.size();
        vector<int> f(n);
        vector<int> from(n);
        int mx = n - 1;
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i + 1; j < n; ++j) {
                if(f[j] > f[i] && groups[i] != groups[j] && check(words[i], words[j])) {
                    f[i] = f[j];
                    from[i] = j;
                }
            }
            f[i]++;
            if(f[i] > f[mx]) {
                mx = i;
            }
        }
        int m = f[mx];
        vector<string> ans(m);
        for(int i = 0; i < m; ++i) {
            ans[i] = words[mx];
            mx = from[mx];
        }
        return ans;
    }
};
