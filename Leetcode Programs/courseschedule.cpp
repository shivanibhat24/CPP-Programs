class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0)q.push(i);
        }
        vector<int> topoSort;
        while(q.size()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topoSort.size() == numCourses;
    }
};
