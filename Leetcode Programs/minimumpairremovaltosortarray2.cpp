
#define ll long long
const ll INF = 1e18;

struct SegmentTreeNode {
    ll val;
    int idx;
    SegmentTreeNode() : val(INF), idx(-1) {}
    void assignLeaf(const pair<ll, int>& p) {
        val = p.first;
        idx = p.second;
    }
    void merge(const SegmentTreeNode& left, const SegmentTreeNode& right) {
        if (left.val <= right.val) {
            val = left.val;
            idx = left.idx;
        } else {
            val = right.val;
            idx = right.idx;
        }
    }
    pair<ll, int> getValue() { return {val, idx}; }
};

inline SegmentTreeNode combine(const SegmentTreeNode &a, const SegmentTreeNode &b) {
    SegmentTreeNode res;
    if(a.val <= b.val) { res.val = a.val; res.idx = a.idx; }
    else { res.val = b.val; res.idx = b.idx; }
    return res;
}

template <class T, class V>
class SegmentTree {
    vector<SegmentTreeNode> nodes;
    int N, base;
public:
    SegmentTree(T arr[], int N) {
        this->N = N;
        base = 1;
        while(base < N) base <<= 1;
        nodes.resize(base * 2);
        for (int i = 0; i < base; i++) {
            if(i < N) {
                nodes[base + i].assignLeaf(arr[i]);
            } else {
                pair<ll,int> p = {INF, i};
                nodes[base + i].assignLeaf(p);
            }
        }
        for (int i = base - 1; i > 0; i--) {
            nodes[i].merge(nodes[i << 1], nodes[(i << 1) | 1]);
        }
    }
    
    ~SegmentTree() { }
    
    V getValue(int lo, int hi) {
        int l = lo + base, r = hi + base;
        SegmentTreeNode resL, resR;
        resL.val = INF; resL.idx = -1;
        resR.val = INF; resR.idx = -1;
        while(l <= r) {
            if(l & 1) {
                resL = combine(resL, nodes[l]);
                l++;
            }
            if(!(r & 1)) {
                resR = combine(nodes[r], resR);
                r--;
            }
            l >>= 1;
            r >>= 1;
        }
        SegmentTreeNode res = combine(resL, resR);
        return res.getValue();
    }
    
    void update(int index, T value) {
        int pos = index + base;
        nodes[pos].assignLeaf(value);
        pos >>= 1;
        while(pos > 0) {
            nodes[pos].merge(nodes[pos << 1], nodes[(pos << 1) | 1]);
            pos >>= 1;
        }
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<ll> a(n);
        vector<int> L(n), R(n);
        vector<bool> act(n, true);
        for (int i = 0; i < n; i++){
            R[i] = (i == n-1 ? -1 : i+1);
            L[i] = i - 1;
            a[i] = nums[i];
        }
        int usCnt = 0;
        int cur = 0;
        while(cur != -1 && R[cur] != -1) {
            if(a[cur] > a[R[cur]])
                usCnt++;
            cur = R[cur];
        }
        vector<pair<ll,int>> base(n);
        for (int i = 0; i < n; i++){
            if(R[i] != -1 && act[i] && act[R[i]])
                base[i] = {a[i] + a[R[i]], i};
            else
                base[i] = {INF, i};
        }
        SegmentTree<pair<ll,int>, pair<ll,int>> st(base.data(), n);
        int ops = 0;
        while(usCnt > 0) {
            pair<ll,int> curPair = st.getValue(0, n-1);
            if(curPair.first == INF) break;
            int i = curPair.second;
            int j = R[i];
            if(j == -1) {
                pair<ll,int> p_val = {(R[i]!=-1 && act[R[i]]) ? a[i] + a[R[i]] : INF, i};
                st.update(i, p_val);
                continue;
            } else {
                if(!act[i]) {
                    pair<ll,int> p_val = {(R[i]!=-1 && act[R[i]]) ? a[i] + a[R[i]] : INF, i};
                    st.update(i, p_val);
                    continue;
                } else {
                    if(!act[j]) {
                        pair<ll,int> p_val = {(R[i]!=-1 && act[R[i]]) ? a[i] + a[R[i]] : INF, i};
                        st.update(i, p_val);
                        continue;
                    } else {
                        if(a[i] + a[j] != curPair.first) {
                            pair<ll,int> p_val = {(R[i]!=-1 && act[R[i]]) ? a[i] + a[R[i]] : INF, i};
                            st.update(i, p_val);
                            continue;
                        }
                    }
                }
            }
            int oldInv = 0;
            if(L[i] != -1 && a[L[i]] > a[i])
                oldInv++;
            if(j != -1 && a[i] > a[j])
                oldInv++;
            if(j != -1 && R[j] != -1 && a[j] > a[R[j]])
                oldInv++;
            a[i] += a[j];
            act[j] = false;
            R[i] = R[j];
            if(R[j] != -1) {
                L[R[j]] = i;
            }
            int newInv = 0;
            if(L[i] != -1 && a[L[i]] > a[i])
                newInv++;
            if(R[i] != -1 && a[i] > a[R[i]])
                newInv++;
            usCnt = usCnt - oldInv + newInv;
            pair<ll,int> p_val = {(R[i]!=-1 && act[R[i]]) ? a[i] + a[R[i]] : INF, i};
            st.update(i, p_val);
            st.update(j, {INF, j});
            if(L[i] != -1 && act[L[i]]) {
                int li = L[i];
                pair<ll,int> p_val2 = {(R[li]!=-1 && act[R[li]]) ? a[li] + a[R[li]] : INF, li};
                st.update(li, p_val2);
            }
            ops++;
        }
        return ops;
    }
};
