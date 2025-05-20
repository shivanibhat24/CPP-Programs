class Solution {
public:
    int minMoves(vector<string>& mat) {
        static const int maxn = (int)1e6 + 1, maxd = 26;
        static int idx[maxn], dis[maxn];
        static vector<int> pos[maxd | 1], que;
        int r = mat.size(), c = mat[0].size(), n = r * c;
        memset(dis, -1, n * sizeof(int));
        for(int i = 0, u = 0; i < r; ++i)
            for(int j = 0; j < c; ++j, ++u) {
                char &ch = mat[i][j];
                idx[u] = ch >= 'A' && ch <= 'Z' ? (ch - 'A') : -1;
                if(idx[u] >= 0)
                    pos[idx[u]].push_back(u);
            }
        auto upd = [&](int u, int d) {
            if(dis[u] != -1)
                return;
            if(idx[u] == -1) {
                dis[u] = d;
                que.push_back(u);
                return;
            }
            for(int v: pos[idx[u]]) {
                dis[v] = d;
                que.push_back(v);
            }
        };
        upd(0, 0);
        for(int i = 0; i < (int)que.size(); ++i) {
            int u = que[i], ux = u / c, uy = u % c;
            for(int dx = -1; dx <= 1; ++dx)
                for(int dy = -1; dy <= 1; ++dy) {
                    if(!dx == !dy)
                        continue;
                    int vx = ux + dx, vy = uy + dy;
                    if(vx < 0 || vx >= r || vy < 0 || vy >= c || mat[vx][vy] == '#')
                        continue;
                    upd(u + dx * c + dy, dis[u] + 1);
                }
            if(dis[n - 1] != -1)
                break;
        }
        que.clear();
        for(int i = 0; i < maxd; ++i)
            pos[i].clear();
        return dis[n - 1];
    }
};
