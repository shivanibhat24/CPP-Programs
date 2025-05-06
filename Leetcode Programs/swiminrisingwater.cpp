class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;        
        int t=grid[0][0];        
        int m=grid[0][0];
        pq.push({m,{0,0}});
        int n=grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int re[]={0,1,-1,0};
        int ce[]={1,0,0,-1};
        while(!pq.empty()){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            int ti=pq.top().first;
            m=ti;
            pq.pop();
            if(i==grid.size()-1 && j==grid.size()-1){
                return m;
            }
            for(int k=0;k<4;k++){
                int rm=i+re[k];
                int cm=j+ce[k];
                if(rm>=0 && rm<grid.size() && cm>=0 && cm <grid[0].size() && !visited[rm][cm]){            visited[rm][cm]=true;
                    pq.push({max(ti,grid[rm][cm]),{rm,cm}});
                }
            }
        }
return -1;
    }
};
