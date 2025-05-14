typedef  long long ll;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m= grid.size(),n= grid[0].size();
        vector<ll> rowSum(m,0), colSum(n,0);
        ll totSum=0;
        for(int i=0;i<m;i++)
        {
            rowSum[i]= accumulate(grid[i].begin(),grid[i].end(),0ll);
            totSum+=rowSum[i];
        }
        if(totSum%2)
            return false;
        ll prefRowSum =0;
        for(int i=0;i<m;i++)
        {
            prefRowSum=prefRowSum+rowSum[i];
            if(totSum/2==(prefRowSum))
            {
                return true;
            }
        }
        ll prefColSum=0;
        for(int j=0;j<n;j++)
        {
            ll sm=0;
            for(int i=0;i<m;i++)
            {
                sm+= 1ll*grid[i][j];
            }
            prefColSum=prefColSum+sm;
            if(totSum/2==(prefColSum))
            {
                return true;
            }
        }
        return false;
    }
};
