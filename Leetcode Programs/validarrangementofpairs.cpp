class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        for (auto& pair : pairs) {
            int u = pair[0];
            int v = pair[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        int startingNode = pairs[0][0];
        for (auto it = adj.begin(); it != adj.end(); it++) {
            if (outdegree[it->first] - indegree[it->first] == 1) 
            {
                startingNode = it->first;
                break;
            }
        }
        stack<int> st;
        vector<int> EulerPath;
        st.push(startingNode);  
        while (!st.empty()) {    
            int curr = st.top();
            if (!adj[curr].empty()) {
                int nbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(nbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }
        reverse(EulerPath.begin() , EulerPath.end() );
        vector<vector<int>> result;
        for(int i = 0 ; i< EulerPath.size()-1 ; i++){
                result.push_back({EulerPath[i] , EulerPath[i+1]});
            
        }
        return result ;
    }
};
