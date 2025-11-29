class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res;
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][1]]++;
        }
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i] == 0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
