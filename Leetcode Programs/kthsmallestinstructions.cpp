class Solution 
{
    public:
    int n,m;
    vector<vector<int>>dp;
    int fill_dp( int i , int j )
    {
        if( i >= n || j >= m || i < 0 || j < 0 )
        return 0;
        if( i == n - 1 && j == m - 1 )
        return 1;
        if( dp[i][j] != -1 )
        return dp[i][j];
        return dp[i][j] = fill_dp(i+1,j) + fill_dp(i,j+1);

    }
    string kthSmallestPath(vector<int>& des, int k) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        n = des[0]+1;
        m = des[1]+1;
        dp.assign(n,(vector<int>(m,-1)));
        fill_dp(0,0);
        string ans = "";
        int r = 0 , c = 0 ;
        while( r != n - 1  && c != m - 1 && k > 0 )
        {
             if( k > dp[r][c+1] )
             {
                ans.push_back('V');
                k -= dp[r][c+1];
                r++;
             }
             else 
             {
                ans.push_back('H');
                c++;
             }
        }
        while( r < n - 1 )
        {
            ans.push_back('V');
            r++;
        }
        while( c < m - 1 )
        {
            ans.push_back('H');
            c++;
        }
        return ans;
    }
};
