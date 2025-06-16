class Solution {
public:
    int findParent(int a, int *parent){
        if (parent[a]!=a) parent[a]=findParent(parent[a],parent);
        return parent[a];
    }
    void merge(int a, int b, int *parent, int *rank, int *size){
        int p1=findParent(a,parent),p2=findParent(b,parent);        
        if (p1==p2) return;
        if (rank[p1]>rank[p2]){
            parent[b]=parent[p2]=p1;
            size[p1]+=size[p2];
        } else if (rank[p1]<rank[p2]){
            parent[a]=parent[p1]=p2;
            size[p2]+=size[p1];
        } else{
            parent[b]=parent[p2]=p1;
            size[p1]+=size[p2];
            rank[p1]++;
        }
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        bool prime[n+1];
        long long ret=0;
        prime[1]=0;
        for (int i=2;i<=n;i++) prime[i]=1;
        for (int i=2;i*i<=n;i++) if (prime[i]){
            for (int j=i*2;j<=n;j+=i) prime[j]=0;
        }
        int parent[n+1],rank[n+1],size[n+1];
        for (int i=1;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
            size[i]=1;
        }
        vector<int> nodes[n+1];
        for (auto &e:edges) {
            if (!prime[e[0]] && !prime[e[1]]) merge(e[0],e[1],parent,rank,size);
            nodes[e[1]].push_back(e[0]);
            nodes[e[0]].push_back(e[1]);
        }
        for (int i=1;i<=n;i++) if (prime[i]){
            int t=0;
            for (auto &c:nodes[i]) if (!prime[c]) t+=size[findParent(c,parent)];
            for (auto &c:nodes[i]) if (!prime[c]) ret+=1l*size[findParent(c,parent)]*(t-size[findParent(c,parent)]+2);
        }
        return ret/2;
    }
};
