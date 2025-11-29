const int N = 100005;

class SegmentTree {
private:
    int n;
    int mn[4 * N], mx[4 * N], sm[4 * N];

public:
    SegmentTree() {}

    void init(int n) {
        this->n = n;
        memset(mn, 0, sizeof(mn[0]) * 4 * n);
        memset(mx, 0, sizeof(mx[0]) * 4 * n);
        memset(sm, 0, sizeof(sm[0]) * 4 * n);
    }

    void set(int b, int val) {
        set(0, 0, n - 1, b, val);
    }

    int get() {
        return get(0, 0, n - 1, 0);
    }

private:
    void set(int x, int L, int R, int b, int val) {
        if (L == R) {
            mn[x] = mx[x] = val;
            sm[x] = val;
            return;
        }
        int mid = (L + R) >> 1;
        int x1 = (x << 1) + 1, x2 = x1 + 1;
        if (mid >= b) set(x1, L, mid, b, val);
        else set(x2, mid + 1, R, b, val);
        mn[x] = min(mn[x1] + sm[x2], mn[x2]);
        mx[x] = max(mx[x1] + sm[x2], mx[x2]);
        sm[x] = sm[x1] + sm[x2];
    }

    int get(int x, int L, int R, int pre) {
        if (L == R) {
            if (mn[x] >= pre && mx[x] <= pre) return L;
            else return L + 1;
        }
        int mid = (L + R) >> 1;
        int x1 = (x << 1) + 1, x2 = x1 + 1;
        if (mn[x1] <= pre - sm[x2] && mx[x1] >= pre - sm[x2]) return get(x1, L, mid, pre - sm[x2]);
        else return get(x2, mid + 1, R, pre);
    }
};

int n;
SegmentTree st;
int pre[N];

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            pre[nums[i]] = -1;
        }
        st.init(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = nums[i];
            if (pre[j] != -1) st.set(pre[j], 0);
            st.set(i, (j & 1) ? 1 : -1);
            pre[j] = i;
            int z = st.get();
            if (z <= i) ans = max(ans, i - z + 1);
        }
        return ans;
    }
};
