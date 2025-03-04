class Solution {
public:
    int minimumDeleteSum(string s1, string s2) 
    {
        int m = s1.size();
        int n = s2.size();
        vector<int> prev(n+1,0),cur(n+1,0);
        for(int i = 1;i<=n;i++)
        {
            prev[i] = prev[i-1] + s2[i-1];
        }
        for(int i=1;i<=m;i++)
        {
            cur[0] = prev[0]+s1[i-1];
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    cur[j] = prev[j-1];
                }
                else
                {
                    cur[j] = min(
                        prev[j] + s1[i-1],
                        cur[j-1] + s2[j-1]
                    );
                }
            }
            prev.swap(cur);
        }
        return prev[n];
    }
};
