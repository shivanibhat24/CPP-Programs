using ll = long long;
const int N = 30, M = 500;
const ll inf = 0x3e3e3e3e3e3e3e3e;
struct Edge{
	int v,next; 
	ll cap,flow, cost; 
}E[M<<1];
int head[N], pre[N], dist[N];
ll maxflow, mincost;
bool vis[N];
int cnt;
void addEdge(int u, int v, ll w, ll c) {
	E[cnt].v = v;
	E[cnt].next = head[u];
	E[cnt].cap = w;
	E[cnt].flow = 0;
	E[cnt].cost = c;
	head[u] = cnt++;
	E[cnt].v = u;
	E[cnt].next = head[v];
	E[cnt].cap = 0;
	E[cnt].flow = 0;
	E[cnt].cost = -c;
	head[v] = cnt++;
}
bool SPFA(int s,int t,int n){
    queue<int> q;  
    memset(vis,false,sizeof(vis)); 
    memset(pre,-1,sizeof(pre)); 
    memset(dist,0x3f,sizeof(dist)); 
    vis[s]=true; 
    dist[s]=0; 
    q.push(s); 
    while(!q.empty()){ 
        int u=q.front(); 
        q.pop(); 
        vis[u]=false; 
        for(int i=head[u];~i;i=E[i].next){ 
            int v=E[i].v; 
            if(E[i].cap>E[i].flow&&dist[v]>dist[u]+E[i].cost){ 
                dist[v]=dist[u]+E[i].cost; 
                pre[v]=i;  
                if(!vis[v]){  
                    q.push(v);    
                    vis[v]=true;  
                } 
            } 
        } 
    } 
    return pre[t]!=-1; 
}
int MCMF(int s,int t,int n){ 
    maxflow=mincost=0;
    while(SPFA(s,t,n)){
        ll d=inf; 
        for(int i=pre[t];~i;i=pre[E[i^1].v]){ 
            d=min(d,E[i].cap-E[i].flow);
        } 
        maxflow+=d;
        for(int i=pre[t];~i;i=pre[E[i^1].v]){  
            E[i].flow+=d; 
            E[i^1].flow-=d; 
        } 
        mincost+=dist[t]*d; 
    }
    return mincost; 
} 
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        memset(head, -1, sizeof(head));
        cnt = 0;
        int n = nums.size();
        int s = 0, t = n + numSlots + 1;
        for(int i=1; i<=n; i++) {
            addEdge(s, i, 1, 0);
        }
        for(int i=n+1; i<=n + numSlots; i++) {
            addEdge(i, t, 2, 0);
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=numSlots; j++) {
                addEdge(i, j+n, 1, -(nums[i-1]&j));
            }
        }
        MCMF(s, t, t);
        return -mincost;        
    }
};
