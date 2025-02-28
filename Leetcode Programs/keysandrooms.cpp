class Solution {
public:
    void traverse(int node,map<int,bool>& vis,vector<vector<int>>& adj)
    {
        vis[node]=true;
        for(auto i:adj[node])
        {
            if(!vis[i])
            {
                traverse(i,vis,adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {      
        int n=rooms.size();
         map<int,bool> vis;
        for(int i=0;i<n;i++)
        {
             vis[i]=false;
        }        
        traverse(0,vis,rooms);
        for(int i=0;i<vis.size();i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
    }
};
