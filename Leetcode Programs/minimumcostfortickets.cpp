class Solution {
public:
    int mincostTickets(vector<int>& DAYS, vector<int>& cost) {        
        unordered_set<int> days(DAYS.begin(),DAYS.end());
        vector<int> dp(367);        
        for(int i=1 ; i<366 ; i++)
        {
            dp[i] = dp[i-1];
            if(days.find(i) != days.end())
            {
                dp[i] = min({ dp[i - 1] + cost[0],   
                             dp[max(0, i - 7)] + cost[1],  
                             dp[max(0, i - 30)] + cost[2]});  
            }
        }
        return dp[365];
    }
};
