vector<int>height;
vector<vector<int>>adj;
vector<int>indeg;
int l=0;
     class compare{
        public:
        bool operator()(int a,int b){
            int amini=INT_MAX;
            for(int i=0;i<adj[a].size();i++){
                amini=min(amini,indeg[adj[a][i]]);
            }
            int bmini=INT_MAX;
            for(int i=0;i<adj[b].size();i++){
                bmini=min(bmini,indeg[adj[b][i]]);
            }
            if(!l&&amini!=bmini)
            return amini>bmini;
            if(height[a]!=height[b])
            return height[a]<height[b];
            else
            return adj[a].size()<adj[b].size();
        }
    };
class Solution {
public:
    int dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&height){
        int h=0;
        visited[node]=1;
        if(adj[node].size()==0){
            height[node]=0;
            return height[node]+1;
        }
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                h=max(h,dfs(adj[node][i],adj,visited,height));
            }
            else{
                h=max(h,1+height[adj[node][i]]);
            }
        }
        height[node]=h;
        return h+1;
    }
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<vector<int>>ad(n);
        for(int i=0;i<relations.size();i++){
            ad[relations[i][0]-1].push_back(relations[i][1]-1);
        }
        adj=ad;

        indeg.resize(n);
        for(int i=0;i<n;i++)
        indeg[i]=0;
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                indeg[adj[i][j]]++;
            }
        }
        height.resize(n);
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i])
            dfs(i,adj,visited,height);
        }
        priority_queue<int,vector<int>,compare>p;
        int baba=0;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                baba++;
            }
        }
        if(baba>k)
        l=baba-k;
        for(int i=0;i<n;i++){
            if(!indeg[i]){
                cout<<i<<" ";
            p.push(i);
            }
        }
        cout<<endl;
        int ans=0;
        while(!p.empty()){
            int n=p.size();
            ans++;
            l=0;
            if(n>k){
            n=k;
            l=n-k;
            }
            vector<int>temp;
            while(n--){
                int node=p.top();
                cout<<node<<" ";
                p.pop();
                for(int i=0;i<adj[node].size();i++){
                    indeg[adj[node][i]]--;
                    if(!indeg[adj[node][i]])
                    temp.push_back(adj[node][i]);
                }
            }
            for(int i=0;i<temp.size();i++)
            p.push(temp[i]);
            cout<<endl;
        }
        return ans;
    }
};
