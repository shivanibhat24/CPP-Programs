int req[100100];
bool done;
void initilize(){
    if(done)return;
    done = true;
    const int mxN = 100000;
    for(int i = 1 ; i <= mxN ; i++)req[i] = i;
    for(int i = 1 ; i * i <= mxN ; i++){
        for(int j = i * i ; j <= mxN ; j += i * i ){
            req[j] = min(req[j] , j / (i * i));
        }
    }
}
int freq[100100];
int val[100100];
vector<int> g[100100];
long long ans;
void dfs(int nn , int pp){
    int rr = req[val[nn]];
    ans += freq[rr];
    freq[rr]++;
    for(auto& v : g[nn]){
        if(v != pp){
            dfs(v , nn);
        }
    }
    freq[rr]--;
}
class Solution {
public:
    long long sumOfAncestors(int n, vector<vector<int>>& adj, vector<int>& nums) {
        initilize();
        ans = 0;
        for(int i = 0 ; i < n ; i++)g[i].clear() , val[i] = nums[i];
        for(auto& edge : adj){
            int u = edge[0] , v = edge[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0 , -1);
        return ans;
    }
};
