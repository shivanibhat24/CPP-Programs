class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<bool> visited(n, false);
        vector<int> res;
        int stars = 0;
        string s = target;
        while (stars < n) {
            bool done = false;
            for (int i = 0; i <= n - m; ++i) {
                if (!visited[i] && canStamp(s, stamp, i)) {
                    stars += doStamp(s, m, i);
                    visited[i] = true;
                    res.push_back(i);
                    done = true;
                    if (stars == n) break;
                }
            }
            if (!done) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    bool canStamp(string& s, string& stamp, int pos) {
        int m = stamp.size();
        bool found = false;
        for (int i = 0; i < m; ++i) {
            if (s[pos + i] == '?') continue;
            if (s[pos + i] != stamp[i]) return false;
            found = true;
        }
        return found;
    }
    int doStamp(string& s, int m, int pos) {
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (s[pos + i] != '?') {
                s[pos + i] = '?';
                ++cnt;
            }
        }
        return cnt;
    }
};
