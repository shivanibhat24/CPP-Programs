using LL = long long;
class Solution {
    int mod = 1e9+7;
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        /*
            find number of way earn exactly target points

            type k
            (count_k, mark_k)
            dp[i]        = prev_dp[i] + prev_dp[i-mark_k] + ... + prev_dp[i-mark_k*count_k]
            dp[i-mark_k] =              prev_dp[i-mark_k] + ... + prev_dp[i-mark_k*count_k] + prev_dp[i-(mark_k+1)*count_k] 

            dp[i] - dp[i-mark_k] = prev_dp[i] - prev_dp[i-(mark_k+1)*count_k]
            dp[i] = dp[i-mark_k] + prev_dp[i] - prev_dp[i-(mark_k+1)*count_k]
        */
        int n = types.size();
        vector<LL> dp(target+1, 0);
        dp[0] = 1;
        for(auto& type: types){
            int count = type[0];
            int mark = type[1];
            auto prev_dp = dp;
            
            for(int i=0; i<=target; i++){
                int prev_last_index = i-(count+1)*mark;
                dp[i] = ((i>=mark ?dp[i-mark] :0) + prev_dp[i] - (prev_last_index>=0 ?prev_dp[prev_last_index] :0)% mod + mod)%mod;
            }
        }
        return dp[target];
    }
};
