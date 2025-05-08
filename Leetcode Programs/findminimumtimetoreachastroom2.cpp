class Solution {
    #define pip pair<int,pair<int,pair<int,int>>>
    bool isValid(int& i,int& j,int& m,int& n)
    {
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
        return false;    
    }
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pip,vector<pip>,greater<pip>> minheap;    
        int i,m=moveTime.size(),n=moveTime[0].size(),a=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector <int> dx={0,0,1,-1};
        vector <int> dy={1,-1,0,0};
        vis[0][0]=true;
        minheap.push({0,{1,{0,0}}});
        while(!minheap.empty())
        {
            pip curr = minheap.top();
            minheap.pop();
            int t=curr.first,x=curr.second.second.first,y=curr.second.second.second,l=curr.second.first,nx,ny;
            for(i=0;i<4;i++)
            {
                nx=x+dx[i];
                ny=y+dy[i];
                if(isValid(nx,ny,m,n) && !vis[nx][ny])
                {                    
                    vis[nx][ny]=true;                  
                    moveTime[nx][ny]=max(t+l,moveTime[nx][ny]+l);
                    if(nx==m-1 && ny==n-1)
                        return moveTime[nx][ny];
                    minheap.push({moveTime[nx][ny],{l^3,{nx,ny}}});
                }
            }
        }
        return moveTime[m-1][n-1];
    }
};
