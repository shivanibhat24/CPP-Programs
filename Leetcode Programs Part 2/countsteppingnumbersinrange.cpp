class Solution {
    const int mod = 1e9+7;
    bool equal_allowed;
    int dp[100][10][2];
    int dfs(int i, int last, bool equal, string &s){
        if(i==s.size()) return (equal)<=(equal_allowed);
        if(dp[i][last][equal]!=-1) return dp[i][last][equal];
        dp[i][last][equal] = 0;
        if(last<9){
            if(!equal) dp[i][last][equal] = (0LL+dp[i][last][equal]+dfs(i+1,last+1,false,s))%mod;
            else if((last+1)<=(s[i]-'0')) dp[i][last][equal] = (0LL+dp[i][last][equal]+dfs(i+1,last+1,(last+1)==(s[i]-'0'),s))%mod;
        }
        if(last>0){
            if(!equal) dp[i][last][equal] = (0LL+dp[i][last][equal]+dfs(i+1,last-1,false,s))%mod;
            else if((last-1)<=(s[i]-'0')) dp[i][last][equal] = (0LL+dp[i][last][equal]+dfs(i+1,last-1,(last-1)==(s[i]-'0'),s))%mod;
        }
        return dp[i][last][equal];
    }
    int count(string &s){
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        for(int i=1;i<s[0]-'0';i++){
            sum = (sum+dfs(1,i,false,s)+0LL)%mod;
        }
        sum = (sum+dfs(1,s[0]-'0',true,s)+0LL)%mod;
        for(int i=1;i<s.size();i++){
            for(int x=1;x<=9;x++){
                sum = (sum+dfs(i+1,x,false,s)+0LL)%mod;
            }
        }        
        return sum;
    }
public:
    int countSteppingNumbers(string low, string high) {
        equal_allowed = true;
        int x = count(high);
        equal_allowed = false;
        int y = count(low);
        return (x-y+mod)%mod;
    }
};
