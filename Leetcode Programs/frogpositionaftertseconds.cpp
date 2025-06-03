class Solution {
public:
    double ans=0;
    int c_t;
    void dfs(vector<int>ad[],int i,int time,int targ,vector<int>&vis,double prob){
        vis[i]=1;
        if(targ==i){
            if(time==c_t)ans=prob;
            else {
                if(time<c_t)
                if(i!=1 && ad[i].size()<=1)ans=prob;
            }
            return;
        }
        for(auto x : ad[i]){
            double sz=ad[i].size();
            if(i!=1)sz--;
            double p=1.0/sz;
            if(!vis[x])
             dfs(ad,x,time+1,targ,vis,prob*p);
        }        
    }
    double frogPosition(int n, vector<vector<int>>& edges, int time, int x) {
        vector<int>ad[n+1];
        c_t=time;
        for(auto x:edges){
            ad[x[0]].push_back(x[1]);
            ad[x[1]].push_back(x[0]);
        }
        vector<int>vis(n+1,0);
        dfs(ad,1,0,x,vis,1);
        if(ad[1].size()==0 && x==1)return 1.0;
       return ans;
    }
};
