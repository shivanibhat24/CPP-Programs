class SegmentTree {
    int n;
    vector<int> lazy;
    vector<int> tree;
    void build(int k, int tl, int tr) {
        lazy[k] = n;
        tree[k] = n - tl;
        if (tl == tr) return;
        int tm = (tl + tr) / 2;
        build(k * 2 + 1, tl, tm);
        build(k * 2 + 2, tm + 1, tr);
        return;
    }
    int query(int k, int tl, int tr, int idx) {
        if (idx <= tl) return 0;
        if (idx >= tr + 1 || tl == tr) return tree[k];
        int tm = (tl + tr) / 2;
        int l = query(k * 2 + 1, tl, tm, idx);
        int r = query(k * 2 + 2, tm + 1, tr, idx);
        return max(l, r);
    }
    int update(int k, int tl, int tr, int idx) {
        if (tl == tr) {
            if (idx > tl) lazy[k] = min(lazy[k], idx);
            return tree[k] = min(tree[k], lazy[k] - tl);
        }
        if (idx <= tl) return tree[k];
        if (idx >= tr + tree[k]) {
            lazy[k * 2 + 1] = min(lazy[k * 2 + 1], idx);
            lazy[k * 2 + 2] = min(lazy[k * 2 + 2], idx);
            return tree[k];
        }
        int tm = (tl + tr) / 2;
        int l = update(k * 2 + 1, tl, tm, idx);
        int r = update(k * 2 + 2, tm + 1, tr, idx);
        return tree[k] = max(l, r);
    }
public:
    SegmentTree(int n): n(n) {
        int size = (1 << ((int)ceil(log2(n)) + 1)) - 1;
        lazy = vector<int>(size);
        tree = vector<int>(size);
        build(0, 0, n - 1);
    }
    int query(int idx) { return query(0, 0, n - 1, idx + 1); }
    void update(int idx) { update(0, 0, n - 1, idx); return; }
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> results;
        SegmentTree ST(min((unsigned long)5E4, 3 * queries.size()));
        for (vector<int>& query: queries) {
            if (query[0] == 1) ST.update(query[1]);
            if (query[0] == 2) results.push_back(ST.query(query[1] - query[2]) >= query[2]);
        }
        return results;
    }
};
