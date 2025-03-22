class UnionFind {
public:
    int root[50], Size[50];
    UnionFind(int N){
        iota(root, root+N, 0);
        fill(Size, Size+N, 1);    
    }
    
    int Find(int x) {
        return (x==root[x]) ? x : root[x] = Find(root[x]);
    }

    bool Union(int x, int y) {       
        x=Find(x), y=Find(y);
        if (x == y) return 0; //already have same root
        if (Size[x] > Size[y]) {
            Size[x] +=Size[y];
            root[y] = x;
        } 
        else {
            Size[y] += Size[x];
            root[x] = y;
        }       
        return 1;// merge 2 disjoint sets
    } 
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        const int m=edges.size();
        if(m==n*(n-1)/2) return 1;

        UnionFind G(n);
        int eN[50]={0};
        for(int i=0; i<m; i++){
            int v=edges[i][0], w=edges[i][1];
            int a=eN[G.Find(v)], b=eN[G.Find(w)];
            if (G.Union(v, w)) eN[G.Find(v)]=a+b+1;
            else eN[G.Find(v)]=a+1; 
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int v=G.Size[i];
            if (G.Find(i)==i && eN[i]==v*(v-1)/2)
                ans++;
        }
        return ans;
    }
};
