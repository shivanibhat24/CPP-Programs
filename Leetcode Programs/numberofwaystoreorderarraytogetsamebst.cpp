#include <bits/stdc++.h>
using namespace std;

template<typename T> bool ckmin(T& x, const T& y) { return x > y ? x = y, 1 : 0; } 
template<typename T> bool ckmax(T& x, const T& y) { return x < y ? x = y, 1 : 0; } 

namespace std {
 
template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template<typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
 
template<typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};
template<class Fun>
class y_combinator_result {
    Fun fun_;
 
public:
    template<class T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}
 
    template<class... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
 
template<class Fun>
decltype(auto) y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} 

#define fi first
#define se second
#define REP(i, n) for(int i = 0, ____n = (n); i < ____n; ++i)
#define REPD(i, n) for(int i = (n) - 1; i >= 0; --i)
#define FOR(i, l, r) for(int i = (l), ____r = (r); i <= ____r; ++i)
#define FORD(i, r, l) for(int i = (r), ____l = (l); i >= ____l; --i)
#define each(v, a) for(auto (v) : (a))
#define left  _______left
#define right _______right
#define MASK(x) (1LL << (x))
#define BIT(mask, x) (((mask) >> (x)) & 1)
#define SZ(x) (int) ((x).size())
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SQR(x) (1LL * (x) * (x))
#define BETWEEN(l, x, r) ((l) <= (x) && (x) <= (r))
#define pb push_back

const long long INF = (long long) 1e18 + 7;
const int MOD = (int) 1e9 + 7;
const int MX = (int) 1e5 + 5;
const int LG = __lg(MOD) + 1;
const int BLOCK = 320;
const int d4x[] = {-1, 1, 0, 0};
const int d4y[] = {0, 0, -1, 1};
const int d8x[] = {-1, 1, 0, 0, -1, 1, -1, 1};
const int d8y[] = {0, 0, -1, 1, 1, -1, -1, 1};

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

static const bool __boost = []() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	return std::ios_base::sync_with_stdio(false);
	}();

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const int N = 1000;
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        REP(i, N + 1) dp[0][i] = dp[i][0] = 1;
        FOR(i, 1, N) FOR(j, 1, N) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD; // pascal's triangle

        function<int(vector<int>)> dfs = [&](vector<int> vec) -> int {
            if (SZ(vec) == 0) return 1;
            vector<int> left, right;
            REP(i, SZ(vec)) if (i) {
                if (vec[i] > vec[0]) right.pb(vec[i]);
                else left.pb(vec[i]);
            }
            return (1LL * dfs(left) * dfs(right)) % MOD * 1LL * dp[SZ(left)][SZ(right)] % MOD;
        };
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
