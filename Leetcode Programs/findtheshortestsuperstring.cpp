class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int dp[4096][12] = {0};
        int failure[12][20] = {0};
        int cost[12][12] = {0};
        int trace_table[4096][12] = {0};
        const int sz = A.size();
        const int dp_sz = 1 << sz;        
        for (int i = 0; i < sz; i++) {
            const int str_sz = A[i].size();            
            failure[i][0] = -1;            
            for (int j = 1, k = -1; j < str_sz; j++) {
                while (k >= 0 && A[i][k + 1] != A[i][j])
                    k = failure[i][k];                
                if (A[i][k + 1] == A[i][j]) k++;                
                failure[i][j] = k;
            }
        }
        for (int i = 0; i < sz; i++) {
            const int i_sz = A[i].size();            
            for (int j = 0; j < sz; j++) {
                if (i != j) {
                    const int j_sz = A[j].size();
                    int h = -1;                
                    for (int k = 0; k < j_sz; k++) {
                        while (h >= 0 && A[i][h + 1] != A[j][k])
                            h = failure[i][h];
                        
                        if (A[i][h + 1] == A[j][k])
                            h++;
                    }
                    cost[j][i] = i_sz - h - 1;
                }
            }
        }
        for (int i = 0; i < sz; i++)
            dp[1 << i][i] = A[i].size();        
        for (int state = 1; state < dp_sz; state++) {
            for (int t1 = state, b1 = t1 & (-t1); t1 ; t1 ^= b1 , b1 = t1 & (-t1)) {
                const int state1 = state ^ b1;
                const int i = __builtin_ctz(b1);
                const int i_sz = A[i].size();                
                for (int t2 = state1, b2 = t2 & (-t2); t2; t2 ^= b2, b2 = t2 & (-t2)) {    
                    const int j = __builtin_ctz(b2);
                    const int tmp = dp[state1][j] + cost[j][i];
                    if (!dp[state][i] || tmp < dp[state][i]) {
                        dp[state][i] = tmp;
                        trace_table[state][i] = j;
                    }
                }
            }
        }
        const auto& last = dp[dp_sz - 1];
        string res;
        int i = std::distance(last, std::min_element(last, last + sz));        
        for (int state = dp_sz - 1, j = trace_table[state][i]; state & (state - 1); state ^= (1 << i), i = j, j = trace_table[state][i])
            res = A[i].substr(A[i].size() - cost[j][i]) + res;        
        return A[i] + res;
    }
};
