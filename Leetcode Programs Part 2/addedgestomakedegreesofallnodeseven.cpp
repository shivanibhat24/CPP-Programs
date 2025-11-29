class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degrees(n + 1, 0);
        for (int i = 0; i < edges.size(); i++){
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        vector<int> uneven;
        for (int i = 1; i <= n; i++){
            if (degrees[i] % 2 == 1) uneven.push_back(i);
        }
        if (uneven.size() == 0) return true;
        if (uneven.size() > 4) return false;
        if (uneven.size() == 2){
            int u = uneven[0];
            int v = uneven[1];
            bool dir = false;
            vector<int> edgestouv(n + 1, 0);
            for (int i = 0; i < edges.size(); i++){
                if ((edges[i][0] == u && edges[i][1] == v) || (edges[i][0] == v && edges[i][1] == u)) dir = true;
                else if (edges[i][0] == u || edges[i][0] == v) edgestouv[edges[i][1]]++;
                else if (edges[i][1] == u || edges[i][1] == v) edgestouv[edges[i][0]]++;
            }
            if (!dir) return true;
            for (int i = 1; i <= n; i++){
                if (edgestouv[i] == 0 && i != u && i != v) return true;
            }
        }
        else {
            int u = uneven[0];
            int v = uneven[1];
            int w = uneven[2];
            int y = uneven[3];
            bool uv = false;
            bool wy = false;
            bool uw = false;
            bool vy = false;
            bool uy = false;
            bool vw = false;
            for (int i = 0; i < edges.size(); i++){
                if ((edges[i][0] == u && edges[i][1] == v) || (edges[i][0] == v && edges[i][1] == u)) uv = true;
                if ((edges[i][0] == w && edges[i][1] == y) || (edges[i][0] == y && edges[i][1] == w)) wy = true;
                if ((edges[i][0] == u && edges[i][1] == w) || (edges[i][0] == w && edges[i][1] == u)) uw = true;
                if ((edges[i][0] == v && edges[i][1] == y) || (edges[i][0] == y && edges[i][1] == v)) vy = true;
                if ((edges[i][0] == u && edges[i][1] == y) || (edges[i][0] == y && edges[i][1] == u)) uy = true;
                if ((edges[i][0] == v && edges[i][1] == w) || (edges[i][0] == w && edges[i][1] == v)) vw = true;

            }
            if ((!uv && !wy) || (!uw && !vy) || (!uy && !vw)) return true;
        }
        return false;
    }
};
