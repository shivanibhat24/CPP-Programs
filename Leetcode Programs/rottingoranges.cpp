class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cntfresh=0;
        int ans=0;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
                else if(grid[i][j]==1){
                    cntfresh++;
                }
            }
        }
        int k=0;
        while(!q.empty()){
            auto it=q.front();
            int t=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            ans=max(ans,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                ans=max(ans,t);
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                    q.push({t+1,{nr,nc}});
                    vis[nr][nc]=1;
                    k++;
                }
            }

        }
        cout<<k;
        if(cntfresh!=k){

            return -1;
        }

        return ans;
    }
};
