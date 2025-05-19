class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<vector<int>> isPrerequisites(n, vector<int>(n, false));
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
            isPrerequisites[it[0]][it[1]] = true; 
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                for(int i = 0; i < n; i++){
                    if(isPrerequisites[i][node]){
                        isPrerequisites[i][it] = true;
                    }
                }
                isPrerequisites[node][it] = true;
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }    
        vector<bool> answer;
        for (auto& q : queries) {
            answer.push_back(isPrerequisites[q[0]][q[1]]);
        }
        return answer;
    }
};
