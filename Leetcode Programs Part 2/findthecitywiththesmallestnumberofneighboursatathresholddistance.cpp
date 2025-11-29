class Solution {
public:
    #define ds pair<int,int>
    int djikstra(int& n,int src,vector<vector<pair<int,int>>>& a1,int& k){
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        priority_queue<ds,vector<ds>,greater<ds>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            int cc=pq.top().second;
            pq.pop();
            for(auto it: a1[cc]){
                int nd=d+it.second;
                if(nd<dist[it.first]){
                    dist[it.first]=nd;
                    pq.push({nd,it.first});
                }
            }
        }
        int c=0;
        for(auto it: dist){
            if(it<=k) c++;
        }
        return c;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        int ans=INT_MAX;
        int city=-1;
        vector<vector<pair<int,int>>> a1(n);
        for(auto it: edges){
            a1[it[0]].push_back({it[1],it[2]});
            a1[it[1]].push_back({it[0],it[2]});
        }
        for(int i=0; i<n; i++){
            if(djikstra(n,i,a1,d)<=ans){
                ans=djikstra(n,i,a1,d);
                city=i;
            }
        }
        return city;
        
        
    }
};
