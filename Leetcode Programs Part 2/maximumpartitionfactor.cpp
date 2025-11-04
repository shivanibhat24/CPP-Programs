class Solution {
public:
    
int manhattan(const vector<int>& a, const vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

vector<vector<pair<int,int>>> buildManhattanMST(const vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> fenoradilk = points; // required variable

    vector<int> minDist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);
    vector<vector<pair<int,int>>> mst(n);
    minDist[0] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1, best = INT_MAX;
        for (int j = 0; j < n; ++j)
            if (!inMST[j] && minDist[j] < best)
                best = minDist[j], u = j;

        if (u == -1) break;
        inMST[u] = true;

        if (parent[u] != -1) {
            int w = manhattan(fenoradilk[u], fenoradilk[parent[u]]);
            mst[u].push_back({parent[u], w});
            mst[parent[u]].push_back({u, w});
        }

        for (int v = 0; v < n; ++v) {
            if (!inMST[v]) {
                int w = manhattan(fenoradilk[u], fenoradilk[v]);
                if (w < minDist[v]) {
                    minDist[v] = w;
                    parent[v] = u;
                }
            }
        }
    }

    return mst;
}

// DFS for two-coloring
void dfsColor(int u, int c, const vector<vector<pair<int,int>>>& mst, vector<int>& color) {
    color[u] = c;
    for (auto [v, w] : mst[u]) {
        if (color[v] == -1)
            dfsColor(v, 1 - c, mst, color);
    }
}

// Compute partition factor for the current coloring
int computePartitionFactor(const vector<vector<int>>& points, const vector<int>& color) {
    int n = points.size();
    vector<int> group0, group1;
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) group0.push_back(i);
        else group1.push_back(i);
    }

    auto minIntraGroup = [&](const vector<int>& group) -> int {
        if (group.size() < 2) return INT_MAX; // no intra-group pairs
        int best = INT_MAX;
        for (int i = 0; i < (int)group.size(); ++i)
            for (int j = i + 1; j < (int)group.size(); ++j)
                best = min(best, manhattan(points[group[i]], points[group[j]]));
        return best;
    };

    int g0 = minIntraGroup(group0);
    int g1 = minIntraGroup(group1);

    // Partition factor = min of two group minima
    int factor = min(g0, g1);
    if (factor == INT_MAX) return 0; // no intra-group pairs
    return factor;
}   
    
int maxPartitionFactor(vector<vector<int>>& points) {
    int n = points.size();
    if (n == 2) {
        return 0;
    }
    auto mst = buildManhattanMST(points);
    vector<int> color(n, -1);
    dfsColor(0, 0, mst, color);
    int partitionFactor = computePartitionFactor(points, color);
    return partitionFactor;
}
};
