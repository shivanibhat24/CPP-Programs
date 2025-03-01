class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int n = heights.size(),m = heights[0].size();
       bool visp[210][210]={0};
        for(int i=0;i<n;i++){
            dfs(i,0,heights,heights[i][0],visp);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,heights,heights[0][j],visp);
        }
        
        bool visa[210][210]={0};

        for(int i=0;i<n;i++){
            dfs(i,m-1,heights,heights[i][m-1],visa);
        }
        for(int j=0;j<m;j++){
            dfs(n-1,j,heights,heights[n-1][j],visa);
        }

        vector<vector<int> >res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visa[i][j] && visp[i][j]){
                   res.push_back({i,j});
                }
            }
        }
        return res;
    }
void dfs(int i,int j, vector<vector<int>>& heights, int last, bool vis[][210]){
     int n = heights.size(), m = heights[0].size();
     if(i<0 || i>=n || j<0 || j>=m){
        return;
     }
     if(vis[i][j] || last>heights[i][j]){
        return;
     }
     vis[i][j]=true;
     dfs(i+1,j,heights,heights[i][j],vis);
     dfs(i,j+1,heights,heights[i][j],vis);
     dfs(i-1,j,heights,heights[i][j],vis);
     dfs(i,j-1,heights,heights[i][j],vis);
    }
};
