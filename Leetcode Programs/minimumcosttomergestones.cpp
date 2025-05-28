class Solution
{
public:
    int mergeStones(vector<int>& stones, int k)
    {
        int n=(int)stones.size();
        if((n-1)%(k-1))
        {
            return -1;
        }
        int prefix[n];
        prefix[0]=stones[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+stones[i];
        }
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int m=k;m<=n;m++)
        {
            for(int i=0;i<=n-m;i++)
            {
                int j=i+m-1;
                dp[i][j]=INT_MAX;
                for(int mid=i;mid<j;mid+=k-1)
                {
                    dp[i][j]=min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
                }
                if((j-i)%(k-1)==0)
                {
                    if(i-1>=0)
                    {
                        dp[i][j]+=prefix[j]-prefix[i-1];
                    }
                    else
                    {
                        dp[i][j]+=prefix[j];
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
