class Solution {
public:
    int findParent(int a, int *parent){
        if (parent[a]!=a) parent[a]=findParent(parent[a],parent);
        return parent[a];
    }
    void merge(int a, int b, int *parent, int *rank){
        int p1=findParent(a,parent),p2=findParent(b,parent);
        if (p1==p2) return;
        if (rank[p1]>rank[p2]){
            parent[b]=parent[p2]=p1;
        } else if (rank[p1]<rank[p2]){
            parent[a]=parent[p1]=p2;
        } else{
            parent[b]=parent[p2]=p1;
            rank[p1]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size(),parent[n],rank[n],next[n],last[n];
        bool b[n];
        for (int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
            last[i]=n;
        }
        for (auto &e:pairs) merge(e[0],e[1],parent,rank);
        for (int i=n-1;i>=0;i--){
            b[i]=1;
            int g=findParent(i,parent);
            next[i]=last[g];
            last[g]=i;
        }
        int c[26];
        for (int i=0;i<26;i++) c[i]=0;
        for (int i=0;i<n;i++){
            int g=findParent(i,parent);
            if (b[g]){
                int p=i,j=0;
                while(p!=n){
                    c[s[p]-'a']++;
                    p=next[p];
                }
                p=i;
                while(p!=n){
                    while(!c[j]) j++;
                    s[p]='a'+j;
                    p=next[p];
                    c[j]--;
                }
                b[g]=0;
            }
        }
        return s;
    }
};
