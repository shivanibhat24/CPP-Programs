class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n-k+1,vector<int>(m-k+1,1e9));
        for(int i=0; i<n-k+1; i++){
            for(int j=0; j<m-k+1; j++){
                vector<int>v;
                for(int x=0; x<k; x++){
                    for(int y=0; y<k; y++){
                        v.push_back(grid[i+x][j+y]);
                    }
                }
                int ind=v.size()-1;
                sort(v.begin(), v.end());
                while(ind>0){
                    if(v[ind]!=v[ind-1]){
                    res[i][j]=min(res[i][j], abs(v[ind]-v[ind-1]));
                    }
                    ind--;
                }
            }
        }
        for(int i=0; i<res.size(); i++){
            for(int j=0; j<res[0].size(); j++){
                if(res[i][j]==1e9) res[i][j]=0;
            }
        }
        return res;
    }    
};
