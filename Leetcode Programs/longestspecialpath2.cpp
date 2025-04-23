class Solution {
public:
    vector<int> longestSpecialPath(const vector<vector<int>>& edges, vector<int>& labels) {
        gr.resize(labels.size(), edges.size());
        for (const auto& e : edges) {
            gr.insert(e[0], e[1], e[2]);
        }
        this->labels = &labels;
        pos.resize(ranges::max(labels) + 1, {-1, -1});
        dfs(0);
        return {bestLen, bestCount};
    }
private:
    struct CompGr {
        int N;
        vector<pair<int, int>> edges;
        vector<int> next;
        int free;
        void resize(int N, int E) {
            this->N = N;
            edges.resize(E << 1);
            next.assign(N + (E << 1), -1);
            free = N;
        }
        void insert(int u, int v, int len) {
            insert_edge(u, v, len);
            insert_edge(v, u, len);
        }
        void insert_edge(int u, int v, int len) {
            edges[free - N] = { v, len };
            next[free] = next[u];
            next[u] = free++;
        }
        bool operator>>(int& it) const {
            it = next[it];
            return it != -1;
        }        const pair<int,int>& operator[](int it) const {
            return edges[it - N];
        }
    };
    CompGr gr;
    const vector<int>* labels{nullptr};
    vector<pair<int, int>> pos;
    int bestLen = -1, bestCount = -1;
    vector<pair<int, int>> st;
    void dfs(int u, int p = -1, int len = 0, int i = 0, int used = -1) {
        int m = st.size();
        st.emplace_back(len, m);
        int lab = labels->at(u);
        auto &labpos = pos[lab];
        auto tmp = labpos;
        int &first = labpos.first;
        int nUsed = used;
        pair<int, int> prev;
        if (used > -1) prev = pos[used];
        if (first < 0) {
            first = m;
        } else if (nUsed < 0) {
            labpos.second = m;
            nUsed = lab;
        } else if (first < pos[nUsed].first) {
            i = max(i, first + 1);
            first = m;
        } else {
            i = max(i, pos[nUsed].first + 1);
            pos[nUsed].first = pos[nUsed].second;
            pos[nUsed].second = -1;
            labpos.second = m;
            nUsed = lab;
        }
        int currLen = len - st[i].first;
        int currCount = m - st[i].second + 1;
        if (currLen > bestLen || (currLen == bestLen && currCount < bestCount)) {
            bestLen = currLen;
            bestCount = currCount;
        }
        for (int it = u; gr >> it; ) {
            auto [v, w] = gr[it];
            if (v == p) continue;
            dfs(v, u, len + w, i, nUsed);
        }
        if (used > -1) pos[used] = prev;
        labpos = tmp;
        st.pop_back();
    }
};
