#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        int lc, rc, cnt;
        long long sum;
        Node(): lc(0), rc(0), cnt(0), sum(0) {}
        Node(int l, int r, int c, long long s): lc(l), rc(r), cnt(c), sum(s) {}
    };
    vector<Node> st;
    vector<int> roots; // roots[i] = version for first i elements (i from 0..n)

    int newNode(const Node& x){ st.push_back(x); return (int)st.size()-1; }

    int update(int prev, int L, int R, int pos, long long val){
        int cur = newNode(st[prev]);
        st[cur].cnt += 1;
        st[cur].sum += val;
        if(L == R) return cur;
        int mid = (L+R)>>1;
        if(pos <= mid){
            int nl = update(st[prev].lc, L, mid, pos, val);
            st[cur].lc = nl;
        }else{
            int nr = update(st[prev].rc, mid+1, R, pos, val);
            st[cur].rc = nr;
        }
        return cur;
    }

    // kth (1-indexed) in (rootR - rootL)
    int kth(int rootL, int rootR, int L, int R, int k){
        if(L==R) return L;
        int leftCnt = st[ st[rootR].lc ].cnt - st[ st[rootL].lc ].cnt;
        int mid = (L+R)>>1;
        if(k <= leftCnt) return kth(st[rootL].lc, st[rootR].lc, L, mid, k);
        return kth(st[rootL].rc, st[rootR].rc, mid+1, R, k-leftCnt);
    }

    // prefix (<= pos) cnt and sum in (rootR - rootL)
    pair<long long,long long> prefix(int rootL, int rootR, int L, int R, int pos){
        if(pos < L) return {0,0};
        if(R <= pos){
            long long c = st[rootR].cnt - st[rootL].cnt;
            long long s = st[rootR].sum - st[rootL].sum;
            return {c,s};
        }
        int mid = (L+R)>>1;
        auto a = prefix(st[rootL].lc, st[rootR].lc, L, mid, pos);
        auto b = prefix(st[rootL].rc, st[rootR].rc, mid+1, R, pos);
        return {a.first + b.first, a.second + b.second};
    }

    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        vector<int> rem(n);
        for(int i=0;i<n;i++) rem[i] = nums[i] % k;

        vector<int> bad(n,0), pref(n,0);
        for(int i=1;i<n;i++) bad[i] = (rem[i]!=rem[i-1]);
        for(int i=1;i<n;i++) pref[i] = pref[i-1] + bad[i];

        vector<long long> B(n);
        for(int i=0;i<n;i++) B[i] = nums[i] / (long long)k;

        // Coordinate compression over B
        vector<long long> vals = B;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int M = (int)vals.size();
        vector<int> idx(n);
        for(int i=0;i<n;i++){
            idx[i] = (int)(lower_bound(vals.begin(), vals.end(), B[i]) - vals.begin()) + 1; // 1..M
        }

        // Persistent segment tree: roots[0] = empty, roots[i] for first i elements
        st.reserve((size_t)(1 + n * 20));
        st.push_back(Node()); // node 0: null
        roots.assign(n+1, 0);
        for(int i=1;i<=n;i++){
            roots[i] = update(roots[i-1], 1, M, idx[i-1], vals[idx[i-1]-1]);
        }

        auto rangeSum = [&](int l, int r)->long long{
            // sum over [l, r] of B
            return st[roots[r+1]].sum - st[roots[l]].sum;
        };

        vector<long long> ans(queries.size(), -1);
        for(size_t qi=0; qi<queries.size(); ++qi){
            int l = queries[qi][0], r = queries[qi][1];
            if(l==r){ ans[qi]=0; continue; }
            // valid iff no remainder change in (l..r]
            if(pref[r] - pref[l] != 0){ ans[qi] = -1; continue; }

            int len = r - l + 1;
            int rootL = roots[l];
            int rootR = roots[r+1];

            int kthIdx = kth(rootL, rootR, 1, M, (len+1)/2);
            long long mVal = vals[kthIdx-1];

            auto pre = prefix(rootL, rootR, 1, M, kthIdx);
            long long cntL = pre.first;
            long long sumL = pre.second;
            long long totSum = rangeSum(l, r);
            long long totCnt = len;

            long long cost = mVal * cntL - sumL + (totSum - sumL) - mVal * (totCnt - cntL);
            ans[qi] = cost;
        }
        return ans;
    }
};
