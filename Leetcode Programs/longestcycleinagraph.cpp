class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>vis(n,0);
        int count = 1;
        int mx = -1;
        for(int i = 0; i< n;i++){
            if(vis[i] > 0) continue;
            int x = i;
            int startPos = count;
            while(x != -1 && !vis[x]){
                vis[x] = count++;
                x = edges[x];
            }
            if(x != -1 && vis[x] >= startPos){
                mx = max(mx, count - vis[x]);
            }
        }
        return mx;
    }
};
