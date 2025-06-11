class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {        
        int i, x, n = prices.size();
        vector<long long> h1(n+1), h2(n+1); 
        long long j, t, y, q, r, *ph = &h1[1], *nh = &h2[1];
        for(i = r = 0; i < k; ++i) {
            for(x = 2*i+1, j = 1e18, t = -1e18, y = 0; x < n; ++x) {
                q = prices[x-1];
                j = min(q-ph[x-2], j); t = max(q+ph[x-2], t);  
                q = prices[x]; nh[x] = y = max(y, max(q-j, t-q));
                r = max(r, y);
            }
            swap(ph, nh);
        }
        return r;
    }
};
