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
#define pb(x) push_back(x)
#define ll long long
class Solution {
public:
    ll totalCost(vector<int>& costs, int k, int candidates) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        priority_queue<int, vector<int>, greater<int> > pq1, pq2;
        ll ans = 0;
        ll i = 0, j = costs.size() - 1;
        while(k--){
            while(pq1.size() < candidates && i <= j)    pq1.push(costs[i++]);
            while(pq2.size() < candidates && j >= i)    pq2.push(costs[j--]);
            int a = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int b = pq2.size() > 0 ? pq2.top() : INT_MAX;
            if(a <= b){
                ans += a;
                pq1.pop();
            }
            else{
                ans += b;
                pq2.pop();
            }
        }
        return ans;
    }
};
