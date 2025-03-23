class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
       for(int i=0;i<roads.size();i++){
          int u=roads[i][0];
          int v=roads[i][1];
          int  time=roads[i][2];
          adj[u].push_back({v,time});
          adj[v].push_back({u,time});
       }
       vector<long long>times(n,INT64_MAX);
       vector<long long>ways(n,0);
       
       priority_queue<pair<long long, long long >,vector<pair<long long, long long >>,greater<pair<long long, long long >>> pq;
         pq.push({0,0});
         ways[0]=1;
         times[0]=0;
           int mod=1e9+7;
         while(!pq.empty()){
           long long time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (time > times[node]) continue;
              for(auto x: adj[node]){
                 long long next_time=x.second;
                 int adj_node=x.first;
                 if(time+next_time<times[adj_node]){
                    times[adj_node]=time+next_time;
                   
                    pq.push({time+next_time,adj_node});
                     ways[adj_node]=ways[node];

                 }
                 else if(time+next_time==times[adj_node]){
                    ways[adj_node]=(ways[node]+ways[adj_node])%mod;
                 }
                 
              }
         }
   return (ways[n-1]%mod); }
};
