class Solution {
public:
    bool helper(vector<int>& stones, int lastInd, int  currInd,vector<vector<bool>>&dp){
        int n = stones.size();
        if(currInd == n-1)return true;
        if(dp[lastInd][currInd])return false;
        int nextInd = currInd +1;
        int lastJump = stones[currInd] - stones[lastInd];
        while(nextInd < n && stones[nextInd] - stones[currInd] <= lastJump +1){
            int nextJump = stones[nextInd] - stones[currInd];
            int jump = nextJump - lastJump;
            if(jump >= -1 && jump <= 1){
                if(helper(stones, currInd, nextInd,dp))return true;
            }
            nextInd++;
        }
        dp[lastInd][currInd] = true;
        return false;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] !=1)return false;
        int n = stones.size();
       vector<vector<bool>> dp(n, vector<bool>(n, 0));
         return helper(stones, 0,1,dp);
    }
};
