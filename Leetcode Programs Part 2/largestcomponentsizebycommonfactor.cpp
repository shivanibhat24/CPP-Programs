class DisjointSet{
    public:
vector<int>parent;
vector<int>size;
DisjointSet(int n){
    parent.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }

}

int findUpar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findUpar(parent[node]);
}

void UnionBySize(int u,int v){
    int ulp_u=findUpar(u);
    int ulp_v=findUpar(v);
    if(ulp_u==ulp_v){
        return;
    }
    if(size[ulp_u]>size[ulp_v]){
        size[ulp_u]+=size[ulp_v];
        parent[ulp_v]=ulp_u;
    }
    else{
        size[ulp_v]+=size[ulp_u];
        parent[ulp_u]=ulp_v;
    }
}


};

class Solution {
public:
vector<int>spf;
void precompute(int n){
spf.resize(n+1);
for(int i=2;i<=n;i++){
    spf[i]=i;
}
for(int i=2;i*i<=n;i++){
    if(spf[i]==i){
    for(int j=i*i;j<=n;j+=i){
       spf[j]=i;
    }
    }
}

}
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>vis(n+1);
        int max_ele=*max_element(nums.begin(),nums.end());
        DisjointSet ds(n);
        precompute(max_ele);
        vector<int>vis(max_ele+1,-1);
        
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                continue;
            }
           int num=nums[i];
           while(num!=1){
            int factor=spf[num];
           if(vis[factor]==-1){
              vis[factor]=i; 
           }
           else{
            ds.UnionBySize(i,vis[factor]);
           }
           num=num/factor;
           }

           
        }
        // for(int j=0;j<=max_ele;j++){
        //     // cout<<
        // }
        int maxi=1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                continue;
            }
            int node=vis[spf[nums[i]]];
            maxi=max(maxi,ds.size[node]);
        }
        return maxi;
    }
};
