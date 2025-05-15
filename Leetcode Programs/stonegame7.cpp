int dp[1000];
class Solution {
public:
    static int stoneGameVII(vector<int>& stones) {
        const int len{static_cast<int>(stones.size()) - 1};
        if(len & 1)
        {
            for(int start{0}; start <= len; ++start)
                dp[start] = stones[start];
            for(int diff{1}; diff < len; diff += 2)
            {
                for(int start{0}; start+diff <= len; ++start)
                    dp[start] = max(dp[start], dp[start+1]
                for(int start{0}; start+diff < len; ++start)
                    dp[start]= min(stones[start]+dp[start+1], stones[start+diff+1]+dp[start]);
            }
            return max(dp[0], dp[1]);
        }
        for(int start{0}; start <= len; ++start)
            dp[start] = 0;
        for(int diff{1}; diff <= len; diff += 2)
        {
            for(int start{0}; start+diff <= len; ++start)
                dp[start] = min(stones[start]+dp[start+1], stones[start+diff]+dp[start]);
            for(int start{0}; start+diff < len; ++start)
                dp[start] = max(dp[start], dp[start+1]);
        }
        return dp[0];
    }
};
