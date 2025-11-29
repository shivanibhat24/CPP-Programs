class Solution {
public:
    int find(int x,vector<int>&parent){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }
    void Union(int x,int y,vector<int>&parent){
        int x_parent=find(x,parent);
        int y_parent=find(y,parent);
        if(x_parent!=y_parent){
            parent[x_parent]=y_parent;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &edge:edges){
            int x=edge[0];
            int y=edge[1];
            int x_parent=find(x,parent);
            int y_parent=find(y,parent);
            if(x_parent!=y_parent){
                Union(x,y,parent);
            }
        }
        int src_parent=find(source,parent);
        int dest_parent=find(destination,parent);
        if(src_parent==dest_parent){
            return true;
        }
        return false;
    }
};
