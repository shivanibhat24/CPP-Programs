int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
int nbi[50001];
pair<int,int> nbs[50000*2], depth[50001];
vector<int> nums;
int bestl, bestn;
void dfs(int n, int p, int curl, int curn, int maxl, int maxn) {
    ++curn;
    int c = nums[n];
    auto [dl, dn] = depth[c];
    if (dl > maxl) maxl = dl, maxn = dn;
    int ll = curl-maxl, nn = curn-maxn;
    if (ll > bestl) bestl = ll, bestn = nn;
    else if (ll == bestl && nn < bestn) bestn = nn;
    for (int i = nbi[n], e = nbi[n+1]; i != e; ++i) if (auto [nb, l] = nbs[i]; nb != p) {
        int nl = curl+l;
        depth[c] = { nl, curn };
        dfs(nb, n, nl, curn, maxl, maxn);
    }
    depth[c] = {dl, dn};
}
class Solution {
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int N = size(nums);
        fill(nbi, nbi+N, 0);
        for (const auto &e : edges) ++nbi[e[0]], ++nbi[e[1]];
        for (int i = 1; i < N; ++i) nbi[i] += nbi[i-1];   nbi[N] = nbi[N-1];
        for (const auto &e : edges) {
            nbs[--nbi[e[0]]] = {e[1], e[2]};
            nbs[--nbi[e[1]]] = {e[0], e[2]};
        }

        bestl = 0; bestn = 1;
        ::nums = move(nums);
        dfs(0, -1, 0, 0, 0, 0);
        return {bestl,bestn};
    }
};
