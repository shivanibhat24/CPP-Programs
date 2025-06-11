struct Tree {
    vector<int> segtree;
    vector<int> lazy;
    Tree(int n) {
        segtree.resize(4*n);
        lazy.resize(4*n);
    }
    int merge(int l, int r) {
        return max(l, r);
    }
    void apply(int idx, int s, int e, int val) {
        segtree[idx] += val;
        lazy[idx] += val;
    }
    void push_down(int idx, int s, int e) {
        if (lazy[idx]) {
            int m = (s + e)/2;
            apply(2*idx, s, m, lazy[idx]);
            apply(2*idx + 1, m + 1, e, lazy[idx]);
            lazy[idx] = 0;
        }
    }
    void update(int idx, int s, int e, int l, int r, int val) {
        if (s > r || l > e || s > e || l > r) return;
        if (l <= s && e <= r) {
            apply(idx, s, e, val);
            return;
        }
        push_down(idx, s, e);
        int m = (s + e)/2;
        update(2*idx, s, m, l, r, val);
        update(2*idx + 1, m + 1, e, l, r, val);
        segtree[idx] = merge(segtree[2*idx], segtree[2*idx + 1]);
    }
    int query(int idx, int s, int e, int l, int r) {
        if (s > r || l > e || s > e || l > r) return INT_MIN;
        if (l <= s && e <= r) return segtree[idx];
        push_down(idx, s, e);
        int m = (s + e)/2;
        auto lans = query(2*idx, s, m, l, r);
        auto rans = query(2*idx + 1, m + 1, e, l, r);
        return merge(lans, rans);
    }
};
#define N 100005
bool prime[N];
auto init = []{
    for (int i = 2; i < N; i++) prime[i] = 1;
    for (int i = 2; i * i < N; i++) if (prime[i])
        for (int j = i * i; j < N; j += i) prime[j] = false;
    return 0;
}();
class Solution {
public:
    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        Tree tree(n);
        unordered_map<int,set<int>> primeToIdx;
        for (int i = 0; i < n; i++) {
            if (prime[nums[i]]) primeToIdx[nums[i]].insert(i);
        }
        for (auto &[prime, listIdx] : primeToIdx) {
            if ((int) listIdx.size() >= 2) {
                int l = (*listIdx.begin()) + 1;
                int r = *listIdx.rbegin();
                tree.update(1, 0, n - 1, l, r, 1);
            }
        }
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            auto &q = queries[i];
            int idx = q[0];
            int oldVal = nums[idx];
            int newVal = q[1];
            if (prime[oldVal]) {
                auto &listIdx = primeToIdx[oldVal];
                int mnIdx = *listIdx.begin();
                int mxIdx = *listIdx.rbegin();
                listIdx.erase(idx);
                if ((int) listIdx.size() && (idx == mnIdx || idx == mxIdx)) {
                    int l = idx, r = -1;
                    if (idx == mnIdx) r = *listIdx.begin();
                    else r = *listIdx.rbegin();
                    if (l > r) swap(l, r);
                    tree.update(1, 0, n - 1, l + 1, r, -1);
                }
                if (!listIdx.size()) primeToIdx.erase(oldVal);
            }
            if (prime[newVal]) {
                auto &listIdx = primeToIdx[newVal];
                if ((int) listIdx.size()) {
                    int mnIdx = *listIdx.begin();
                    int mxIdx = *listIdx.rbegin();
                    if (idx < mnIdx || idx > mxIdx) {
                        int l = idx, r = -1;
                        if (idx < mnIdx) r = mnIdx;
                        else r = mxIdx;
                        if (l > r) swap(l, r);
                        tree.update(1, 0, n - 1, l + 1, r, 1);
                    }
                }
                listIdx.insert(idx);
            }

            nums[idx] = newVal;
            ans[i] = (int) primeToIdx.size() + tree.query(1, 0, n - 1, 0, n - 1);
        }
        return ans;
    }
};
