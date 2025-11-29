class Solution {
public:
vector<vector<int>> ans;
vector<int> path;

int n;
void dfs(int node,vector<vector<int>>& graph){
     path.push_back(node);
     for(int child : graph[node]){
        dfs(child,graph);
     }
     if(node==n-1){
          ans.push_back(path);
     }
     path.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();

        dfs(0,graph);

        return ans;
    }
};
