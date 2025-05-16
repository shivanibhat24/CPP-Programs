class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        const size_t sz = nums.size();
        const size_t lim = limit + 2;
        vector<vector<unordered_set<int>>> dp(lim, vector<unordered_set<int>>(2)); 
        dp[1][1].insert(0);
        dp[limit + 1][1].insert(0);
        if(k > (int)sz * 12 || k + (int)sz * 6 < 0) {
            return -1;
        }
        int ones = 0;
        for(int num: nums) {
            if(num == 1) {
                ones++;
            } 
            if (num == 0) {
                for(int x: dp[limit + 1][1]) {
                    dp[0][0].insert(x);
                }
                for(int x: dp[limit + 1][0]) {
                    dp[0][1].insert(x);
                }
                for(int x: dp[0][0]) {
                    dp[limit + 1][0].insert(x); 
                }
                for(int x: dp[0][1]) {
                    dp[limit + 1][1].insert(x); 
                }
            } else {
                for(size_t j = lim - 1; j < lim; j--) {
                    for(int i : dp[j][0]) {
                        if(j * num <= limit) {
                            dp[j * num][1].insert(i - num);
                        }
                        dp[limit + 1][1].insert(i - num);
                    }
                    for(int i : dp[j][1]) {
                        if(j * num <= limit) {
                            dp[j * num][0].insert(i + num);
                        }
                        dp[limit + 1][0].insert(i + num);
                    }
                }
            }
        }
        if(ones < 2) {
            dp[1][1].erase(0);
        }
        int best = -1;
        for(size_t j = 0; j <= limit; j++) {
            if(dp[j][0].contains(k) || dp[j][1].contains(k)) {
                best = j;
            }
        }
        return best;
    }
};
