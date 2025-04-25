class Solution {
public:
    struct state {
        int len = 0, link = -1;
        unordered_map<int, int> next;
    };
    void sa_extend(vector<state>& st, int c, int& sz, int& last) const {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && !st[p].next.count(c)) {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].next = st[q].next;
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c] == q) {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        nth_element(
            begin(paths), begin(paths), end(paths),
            [](const auto& a, const auto& b) { return a.size() < b.size(); });
        vector<state> st(paths[0].size() * 2);
        int sz = 1, last = 0;
        for (auto n : paths[0])
            sa_extend(st, n, sz, last);
        vector<int> m_cnt(st.size(), INT_MAX), cnt(st.size());
        for (int i = 1; i < paths.size(); ++i) {
            for (int j = 0, v = 0, l = 0; j < paths[i].size(); ++j) {
                while (v && !st[v].next.count(paths[i][j])) {
                    v = st[v].link;
                    l = st[v].len;
                }
                if (st[v].next.count(paths[i][j])) {
                    v = st[v].next[paths[i][j]];
                    cnt[v] = max(cnt[v], ++l);
                    for (int sv = st[v].link; sv && cnt[sv] < st[sv].len;
                         sv = st[sv].link)
                        cnt[sv] = st[sv].len;
                }
            }
            transform(begin(m_cnt), end(m_cnt), begin(cnt), begin(m_cnt),
                      [](int a, int b) { return min(a, b); });
            if (i != paths.size() - 1)
                fill(begin(cnt), end(cnt), 0);
        }
        return max(0, *max_element(begin(m_cnt), end(m_cnt)));
    }
};
