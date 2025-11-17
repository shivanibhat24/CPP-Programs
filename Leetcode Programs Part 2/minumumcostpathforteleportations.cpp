class Solution {
     int dp[82][82][11];
 public:   
    int solve(int i ,int j,int moves,vector<vector<int>>& grid, int k){
           if(i == grid.size()-1 && j == grid[0].size()-1) return 0;
           if(i>=grid.size() || j>=grid[0].size()) return 1e9;
          if(dp[i][j][moves]!=-1) return dp[i][j][moves];        
          int option1 = 1e9;
          int option2 = 1e9;
          int option3 = 1e9;
          if(i+1<grid.size()){
             option1 = grid[i+1][j] + solve(i+1,j,moves,grid,k);
          }
          if(j+1<grid[0].size()){
             option2 = grid[i][j+1] + solve(i,j+1,moves,grid,k);
          }
          for(int x = 0;x<grid.size();x++){
            for(int y = 0;y<grid[0].size();y++){
               if((x!=i || y!=j) && grid[x][y] <= grid[i][j]){
                    if(moves+1<=k){
                         option3 = min(option3,solve(x,y,moves+1,grid,k));
                    }
               }  
            }
          }          
         return dp[i][j][moves] = min({option1,option2,option3});
    }  
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                for(int x = 0;x<=k;x++){
                    dp[i][j][x] = 1e9;
                }
            }
        }
        int maxi = -1e9;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                maxi = max(maxi,grid[i][j]);
            }
        }        
        vector<int>suffix_min(maxi+2,1e9);
        dp[0][0][0] = 0; 
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0 && j==0) continue;
                if(i>0) dp[i][j][0] = min(dp[i][j][0],grid[i][j]+dp[i-1][j][0]);
                if(j>0) dp[i][j][0] = min(dp[i][j][0],grid[i][j]+dp[i][j-1][0]); 
            }
        }
        for(int teleport = 1;teleport<=k;teleport++){
             for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    suffix_min[grid[i][j]] = min( suffix_min[grid[i][j]], dp[i][j][teleport-1] );
                }
             }  
             for(int i = maxi;i>=0;i--){
                suffix_min[i] = min(suffix_min[i],suffix_min[i+1]);
             }
             for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                      dp[i][j][teleport] = dp[i][j][teleport-1];
        if(i > 0)
            dp[i][j][teleport] = min(dp[i][j][teleport], dp[i-1][j][teleport] + grid[i][j]);
        if(j > 0)
            dp[i][j][teleport] = min(dp[i][j][teleport], dp[i][j-1][teleport] + grid[i][j]);
        dp[i][j][teleport] = min(dp[i][j][teleport], suffix_min[grid[i][j]]);
                }
             }
        } 
      int ans = 1e9;
      for(int i = 0;i<=k;i++){
         ans = min(ans,dp[n-1][m-1][i]);
      }
      return ans;
    }
};
