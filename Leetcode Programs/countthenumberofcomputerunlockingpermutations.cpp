class Solution {
public:
    int countPermutations(vector<int>& c) {
        int MOD = 1e9 + 7;
        int n = c.size();
        bool isSolve = true;
        for(int i = 1; i < n; i++) {
            if(c[i] <= c[0]) {isSolve = false; break;}
        }
        if(!isSolve) return 0;        
        long long ans = 1;
        for (int i = 2; i < n; ++i) {
            ans = ans * i % MOD;
        }
        return (int)ans;        
    }
};
