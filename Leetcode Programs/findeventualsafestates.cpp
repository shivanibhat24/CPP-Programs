class Solution {
public:
    bool isCyclic( int node, vector<bool> &visited, vector<bool> &dfsvisited, vector<vector<int>> &graph){
        if(visited[node] && dfsvisited[node])
            return true;        
        visited[node]=true;
        dfsvisited[node]=true;
        for(auto i: graph[node]){
            if(!visited[i]){
                if(isCyclic(i,visited,dfsvisited,graph))
                    return true;
            }
            else if(dfsvisited[i])
                return true;
        }
        dfsvisited[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> visited(n,false), dfsvisited(n,false);
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(!isCyclic(i,visited,dfsvisited,graph))
                    ans.push_back(i);
            }
            else if(!dfsvisited[i])
                ans.push_back(i);
        }
        return ans;
    }
};
