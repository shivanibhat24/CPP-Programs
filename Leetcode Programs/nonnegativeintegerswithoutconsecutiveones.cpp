class Solution {
public:
    int dp[32][2][2];
    int find(int pos, bool small, int prev, string &s)
    {
        if(pos == s.size()) return 1;
        if(dp[pos][small][prev] != -1) return dp[pos][small][prev];
        int ans = 0;
        if(small == true)
        {
            if(prev == 1)
            ans += find(pos+1,small,0,s);
            else
            ans += find(pos+1,small,1,s) + find(pos+1,small,0,s);
        }
        else
        {
            if(prev == 1)
            {
                if(s[pos] == '1')
                ans += find(pos+1,true,0,s);
                else
                ans += find(pos+1,small,0,s);
            }
            else
            {
                if(s[pos] == '1')
                ans += find(pos+1,small,1,s) + find(pos+1,true,0,s);
                else
                ans += find(pos+1,small,0,s);
            }
        }
        return dp[pos][small][prev]=ans;
    }
    int findIntegers(int n) {
        memset(dp,-1,sizeof(dp));
        string str = "";
        while(n)
        {
            if(n&1) str.push_back('1');
            else str.push_back('0');
            n>>=1;
        }
        reverse(begin(str),end(str));
        return find(0,false,0,str);
    }
};
