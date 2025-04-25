const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
class Solution {
public:
    vector<vector<int>> ans;

    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void tarjan(int u, int from)
    {
        dfn[u] = low[u] = ++timestamp;
        for(int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if(!dfn[j])
            {
                tarjan(j, i);
                low[u] = min(low[u], low[j]);
                if(dfn[u] < low[j]) ans.push_back({j, u});
            }
            else if(i != (from ^ 1)) low[u] = min(low[u], low[j]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        memset(h, -1, n * 4);
        memset(dfn, 0, n * 4);
        idx = timestamp = 0;
        for(auto &c : connections)
        {
            int a = c[0], b = c[1];
            add(a, b), add(b, a);
        }    
        tarjan(0, -1);
        return ans;
    }
};
