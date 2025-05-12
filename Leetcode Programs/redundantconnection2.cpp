class DisjointSet
{
    int *parent;
    int *treeSize;
    int n;
public:
    DisjointSet(int n)
    {
        this->n = n;
        parent = new int[n];
        treeSize = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            treeSize[i] = 1;
        }
    }
    int find(int x)
    {
        if (x < 0 || x >= this->n)
            return -1;
        if (x == parent[x])
            return x;
        int root = find(parent[x]);
        parent[x] = root;
        return root;
    }
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
    void doUnion(int x, int y)
    {
        int root1 = find(x);
        int root2 = find(y);

        if (root1 == root2)
            return;

        if (this->treeSize[root1] <= this->treeSize[root2])
        {
            parent[root1] = root2;
            this->treeSize[root2] += this->treeSize[root1];
        }
        else
        {
            parent[root2] = root1;
            this->treeSize[root1] += this->treeSize[root2];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = 0;
        for(const auto &e : edges)
        {
            n = max(n, e[0]);
            n = max(n, e[1]);
        }    
        DisjointSet ds(n);        
        vector<int> indeg(n, 0);
        int maxIndeg = 0;
        for(const auto &e: edges)
        {
            int v = e[1] - 1;
            indeg[v]++;
            maxIndeg = max(maxIndeg, indeg[v]);
        }
        if(maxIndeg == 1)
        {
            vector<int> res = {-1,-1};
            for(const auto &e : edges)
            {
                int u = e[0] - 1;
                int v = e[1] - 1;
                if(ds.connected(u, v))
                    res = {u+1, v+1};
                ds.doUnion(u, v);    
            }
            return res;
        }
        else
        {
            vector<int> e1 = {-1, -1};
            vector<int> e2 = {-1, -1};
            for(const auto &e : edges)
            {
                int u = e[0] - 1;
                int v = e[1] - 1;
                if(indeg[v] == 2)
                {
                    if(e1 == vector<int>({-1,-1}) )
                        e1 = {u,v};
                    else
                        e2 = {u,v};    
                }
            }
            for(const auto &e : edges)
            {
                int u = e[0] - 1;
                int v = e[1] - 1;
                if(e2 != vector<int>({u,v}) )
                    ds.doUnion(u, v);
            } 
            if(ds.connected(e2[0], e2[1]))
                return {e2[0] + 1, e2[1] + 1};
            else
                return {e1[0] + 1, e1[1] + 1};   

        }
    }
};
