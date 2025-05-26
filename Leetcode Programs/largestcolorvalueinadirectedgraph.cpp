class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int min=1000,max=0;
        for (auto &c:colors){
            if (c>max) max=c;
            if (c<min) min=c;
        }
        int n=colors.size(),f[n][max-min+1],c[n],cnt=0,ret=0;
        for (int i=0;i<n;i++){
            c[i]=0;
            for (int j=0;j<max-min+1;j++) f[i][j]=0;
        }
        vector<int> parents[n];
        for (auto &e:edges){
            c[e[0]]++;
            parents[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for (int i=0;i<n;i++) if (c[i]==0){
            q.push(i);
        }
        while (!q.empty()){
            int k=q.front();
            q.pop();
            f[k][colors[k]-min]++;
            cnt++;
            for (int i=0;i<max-min+1;i++) if (f[k][i]>ret) ret=f[k][i];
            for (auto &p:parents[k]){
                if (c[p]--==1) q.push(p);
                for (int i=0;i<max-min+1;i++) if (f[p][i]<f[k][i]) f[p][i]=f[k][i];
            }
        }
        if (cnt!=n) return -1;
        return ret;
    }
};
