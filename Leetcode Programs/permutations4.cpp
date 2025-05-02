vector<long long> f = {1};
int init = []() {
    for (int i = 1; f.back() < 1e16; i++) {
        f.push_back(f.back() * i);
        f.push_back(f.back() * i);
    }
    return 0;
}();
class Solution {
   public:
    vector<int> permute(int n, long long k) {
        if (n < f.size() && k > f[n] * (2 - n % 2)) {  
            return {};
        }
        k--;
        vector<int> cand[2];
        for (int i = 1; i <= n; i++) {
            cand[i % 2].push_back(i);
        }
        vector<int> ans(n);
        int parity = 1;  
        for (int i = 0; i < n; i++) {
            int j = 0;
            if (n - 1 - i < f.size()) {
                long long size = f[n - 1 - i];
                j = k / size;  
                k %= size;
                if (n % 2 == 0 && i == 0) {
                    parity = 1 - j % 2;
                    j /= 2;
                }
            } else {
            }            
            ans[i] = cand[parity][j];
            cand[parity].erase(cand[parity].begin() + j);
            parity ^= 1;  
        }
        return ans;
    }
};
