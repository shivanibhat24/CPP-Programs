struct FenwickTree {
    int n;
    vector<long long> bit;

    FenwickTree(int n, int m) : n(n), bit(n + 1, 0) {
        for (int i = 1; i <= n; ++i) {
            bit[i] += m;
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    inline void add(int i, long long v) {
        while (i <= n) {
            bit[i] += v;
            i += i & -i;
        }
    }

    inline long long prefix_sum(int i) const {
        long long s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    inline long long range_sum(int r) const { return prefix_sum(r + 1); }
};

struct SegmentTree {
    int n, c;
    vector<int> tree, ITL;

    SegmentTree(int n, int c) : n(n), c(c), tree(4 * n, c), ITL(n) {
        build(1, 0, n - 1);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            ITL[l] = node;
            return;
        }
        int m = (l + r) >> 1;
        build(node << 1, l, m);
        build(node << 1 | 1, m + 1, r);
    }

    inline void point_update(int idx, int v) {
        int node = ITL[idx];
        tree[node] = v;
        for (node >>= 1; node >= 1; node >>= 1)
            tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }

    int find_row(int k, int maxRow) {
        return query(1, 0, n - 1, k, maxRow);
    }

    int query(int node, int l, int r, int k, int maxRow) {
        if (l > maxRow || tree[node] < k)
            return -1;
        if (l == r)
            return l;
        
        int m = (l + r) >> 1;
        int left = query(node << 1, l, m, k, maxRow);
        if (left != -1) return left;
        return query(node << 1 | 1, m + 1, r, k, maxRow);
    }
    
    inline int get(int idx) const {
        return tree[ITL[idx]];
    }
};

class BookMyShow {
public:
    int n, m, ptr;
    SegmentTree st;
    FenwickTree bit;

    BookMyShow(int n, int m) : n(n), m(m), ptr(0), st(n, m), bit(n, m) {}

    vector<int> gather(int k, int maxRow) {
        int row = st.find_row(k, maxRow);
        if (row == -1) return {};

        int available = st.get(row);
        int start_col = m - available;
        
        st.point_update(row, available - k);
        bit.add(row + 1, -k);
        
        return {row, start_col};
    }

    bool scatter(int k, int maxRow) {
        long long total = bit.range_sum(maxRow);
        if (total < k) return false;

        long long rem = k;
        for (int i = ptr; i <= maxRow && rem > 0; ++i) {
            int available = st.get(i);
            if (available == 0) {
                ptr = i + 1;
                continue;
            }

            int used = min((long long)available, rem);
            st.point_update(i, available - used);
            bit.add(i + 1, -used);
            rem -= used;
            
            if (available == used) ptr = i + 1;
        }
        return rem == 0;
    }
};
