#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        int prod;                // product of segment % K
        bool isEmpty;            // true for neutral nodes
        array<int,5> rem;        // rem[r] = number of prefixes with residue r (use first K entries)
        Node() {
            prod = 1;
            isEmpty = true;
            rem.fill(0);
        }
    };

    vector<Node> seg;
    int n, K;

    // merge children into parent index `idx`
    void mergeAt(int idx, int left, int right) {
        if (seg[left].isEmpty) {
            seg[idx] = seg[right];
            return;
        }
        if (seg[right].isEmpty) {
            seg[idx] = seg[left];
            return;
        }
        seg[idx].isEmpty = false;
        // compute product
        seg[idx].prod = (int)((1LL * seg[left].prod * seg[right].prod) % K);

        // zero-out rem (only first K used)
        for (int t = 0; t < K; ++t) seg[idx].rem[t] = 0;

        // copy left prefixes
        for (int t = 0; t < K; ++t) {
            int c = seg[left].rem[t];
            if (c) seg[idx].rem[t] += c;
        }

        // add right prefixes shifted by left.prod
        for (int t = 0; t < K; ++t) {
            int c = seg[right].rem[t];
            if (c == 0) continue;
            int newR = (int)((1LL * seg[left].prod * t) % K);
            seg[idx].rem[newR] += c;
        }
    }

    void build(int node, int l, int r, const vector<int>& nums) {
        if (l == r) {
            seg[node].isEmpty = false;
            for (int t = 0; t < K; ++t) seg[node].rem[t] = 0;
            seg[node].prod = nums[l] % K;
            seg[node].rem[ seg[node].prod ] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(node<<1, l, mid, nums);
        build(node<<1|1, mid+1, r, nums);
        mergeAt(node, node<<1, node<<1|1);
    }

    void updatePoint(int node, int l, int r, int pos, int val) {
        if (l == r) {
            seg[node].isEmpty = false;
            for (int t = 0; t < K; ++t) seg[node].rem[t] = 0;
            seg[node].prod = val % K;
            seg[node].rem[ seg[node].prod ] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) updatePoint(node<<1, l, mid, pos, val);
        else updatePoint(node<<1|1, mid+1, r, pos, val);
        mergeAt(node, node<<1, node<<1|1);
    }

    // count prefixes in [ql, qr] whose product%K == x.
    // traverses left-to-right, using `cur` as product of everything to the left processed so far.
    int countRange(int node, int l, int r, int ql, int qr, int &cur, int x) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) {
            int add = 0;
            // for each residue t in this node, after multiplying by cur it becomes (cur * t) % K
            for (int t = 0; t < K; ++t) {
                int c = seg[node].rem[t];
                if (c == 0) continue;
                if ((1LL * cur * t) % K == x) add += c;
            }
            cur = (int)((1LL * cur * seg[node].prod) % K);
            return add;
        }
        int mid = (l + r) >> 1;
        int res = 0;
        res += countRange(node<<1, l, mid, ql, qr, cur, x);
        res += countRange(node<<1|1, mid+1, r, ql, qr, cur, x);
        return res;
    }

    // main API
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = (int)nums.size();
        K = k;
        if (n == 0) return {};
        seg.clear();
        seg.resize(4*n + 5); // default-initialized nodes (isEmpty = true)
        build(1, 0, n-1, nums);

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            updatePoint(1, 0, n-1, idx, val);
            if (start >= n) { ans.push_back(0); continue; }
            int cur = 1;
            int cnt = countRange(1, 0, n-1, start, n-1, cur, x);
            ans.push_back(cnt);
        }
        return ans;
    }
};
