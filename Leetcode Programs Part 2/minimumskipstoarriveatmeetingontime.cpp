class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {        
        int n=dist.size();
        double time[n];        
        for(int i=0;i<dist.size();i++){
            time[i]=dist[i]*1.0/speed;
        }        
        double dp[n][n];
        memset(dp, 0, sizeof(dp));        
        for(int i=0;i<n;i++){            
            for(int j=0;j<=i;j++){                
                if(i==0 && j==0) dp[i][j]=time[i];                                        
                else if(j==0) dp[i][0] = ceil(dp[i-1][j]- 0.00000001)+time[i];           
                else if(i==j) dp[i][j] = dp[i-1][j-1]+time[i];                           
                else dp[i][j] = min(ceil(dp[i-1][j]- 0.00000001), dp[i-1][j-1]) +time[i]; 
            } 
        }        
        for(int i=0;i<n;i++){
            if(dp[n-1][i]<=hoursBefore) return i;
        }        
        return -1;
    }
};
