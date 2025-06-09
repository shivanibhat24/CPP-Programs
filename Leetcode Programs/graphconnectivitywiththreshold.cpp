class Solution {
public:    
    vector<int> par;
    vector<int> sz;
    int findpar(int x){

        if(x == par[x])     return x;
        return par[x] = findpar(par[x]);
    }
    void unionbysize(int a, int b){
        int up_a = findpar(a);
        int up_b = findpar(b);
        if(up_a == up_b)     return;
        if(sz[up_a] > sz[up_b]){
            sz[up_a] += sz[up_b];
            par[up_b] = up_a;
        }
        else{
            sz[up_b] += sz[up_a];
            par[up_a] = up_b;
        }
    } 
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {        
        par = vector<int>(n+1);
        sz = vector<int>(n+1, 1);
        for(int i=0 ; i<=n ; i++)     par[i]=i;
        for(int i=threshold+1 ; i<=n ; i++){
            for(int j=i+i ; j<=n ; j+=i){
                unionbysize(i, j);
            }
        } 
        vector<bool> res;
        for(auto & q: queries){
            if(findpar(q[0]) == findpar(q[1]))     res.push_back(true);
            else                                   res.push_back(false); 
        }
        return res;
    }
};
