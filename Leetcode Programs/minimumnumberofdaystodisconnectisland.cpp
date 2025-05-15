class Solution {
public:
    vector<vector<int>> disc;
    vector<vector<int>> lowt;
    int timer=0;
    int critical_edge=0;
    int land_cell=0;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    bool hasArticulationPoint =false;
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int pi, int pj){
        disc[i][j]=timer;
        lowt[i][j]=timer;
        land_cell++;
        timer++;
        int child=0;
        for(int k=0;k<4;k++){
            int i_=i+dx[k],j_=dy[k]+j;
            if( i_>=0 and j_>=0 and i_< m and j_<n and grid[i_][j_]==1){
                
                if(disc[i_][j_]==-1){
                    dfs(grid,i_,j_,m,n,i,j);
                    lowt[i][j]=min(lowt[i_][j_],lowt[i][j]);
                    if(lowt[i_][j_]>=disc[i][j] and pi!=-1 ){
                        hasArticulationPoint =true;
                    }
                    child++;
                }
                else if(i_!=pi || j_!=pj){
                    lowt[i][j]=min(lowt[i][j],disc[i_][j_]);
                }
                
            }
        }
        if (pi == -1 && child > 1) {
            hasArticulationPoint =true;
        }
    }

    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        disc.resize(m,vector<int>(n,-1));
        lowt.resize(m,vector<int>(n,-1));
        timer=0;
        critical_edge=0;
        
        int isLandcount=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]== 1 and disc[i][j]==-1){
                    dfs(grid,i,j,m,n,-1,-1);
                    isLandcount++;
                }
                
            }
        }

        if(isLandcount==0 || isLandcount >= 2) return 0;
        if(land_cell==1) return 1;

        if(hasArticulationPoint)
            return 1;
        return 2;
    }
};
