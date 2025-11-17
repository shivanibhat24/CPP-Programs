using ll = long long;
static const ll INF = (ll)1e18;
static int ARR[1000];
static int TMP[1000];
struct State {
    ll val;
    int seg;
    State(ll v = -INF, int s = 0) : val(v), seg(s) {}
};
static inline State better(const State& a, const State& b) {
    if (a.val != b.val) return (a.val > b.val) ? a : b;
    return (a.seg < b.seg) ? a : b;
}
static inline State run_f(const int* a, int n, ll cost) {
    State out(0, 0), in1(-INF, 0), in2(-INF, 0);
    for (int i = 0; i < n; ++i) {
        const int x = a[i];
        State c1(out);
        State c2(in1.val == -INF ? State(-INF, 0) : State(in1.val + x, in1.seg));
        State c3(in2.val == -INF ? State(-INF, 0) : State(in2.val - x, in2.seg));
        State next_out = better(c1, better(c2, c3));
        State cand_in1(out.val - x - cost, out.seg + 1);
        State next_in1 = better(in1, cand_in1);
        State cand_in2(out.val + x - cost, out.seg + 1);
        State next_in2 = better(in2, cand_in2);
        out = next_out;
        in1 = next_in1;
        in2 = next_in2;
    }
    return out;
}
static inline ll run(const int* a, int n, int k) {
    ll left = -1, right = INF;
    while (left + 1 < right) {
        ll mid = (left + right) >> 1;
        State s = run_f(a, n, mid);
        if (s.seg > k) left = mid;
        else right = mid;
    }
    State s = run_f(a, n, right);
    return s.val + right * (ll)k;
}
class Solution {
public:
    long long maximumScore(vector<int>& v, int k) {
        const int n = (int)v.size();
        for (int i = 0; i < n; ++i) ARR[i] = v[i];
        int mnVal = ARR[0], mnIdx = 0;
        for (int i = 1; i < n; ++i) {
            if (ARR[i] < mnVal) { mnVal = ARR[i]; mnIdx = i; }
        }
        for (int i = 0; i < n; ++i) TMP[i] = ARR[(i + mnIdx) % n];
        for (int i = 0; i < n; ++i) ARR[i] = TMP[i];
        ll best = run(ARR, n, k);
        for (int i = 0; i < n; ++i) TMP[i] = ARR[(i + 1) % n];
        for (int i = 0; i < n; ++i) ARR[i] = TMP[i];
        best = max(best, run(ARR, n, k));
        return best;
    }
};
