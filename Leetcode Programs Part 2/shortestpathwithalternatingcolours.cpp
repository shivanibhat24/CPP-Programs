class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : redEdges) adj[e[0]].push_back({e[1], 1});  // red = 1
        for (auto &e : blueEdges) adj[e[0]].push_back({e[1], 2}); // blue = 2

        vector<int> res(n, -1);

        // visited[node][color]  →  color 1 = red, 2 = blue
        vector<vector<int>> visited(n, vector<int>(3, 0));

        queue<vector<int>> q;
        // State format: {node, steps, lastColor}

        q.push({0, 0, 0});    // start: node=0, steps=0, lastColor=0
        visited[0][0] = 1;
        res[0] = 0;

        while (!q.empty()) {
            vector<int> state = q.front();
            q.pop();

            int node = state[0];
            int steps = state[1];
            int lastColor = state[2];

            for (auto &edge : adj[node]) {
                int nxt = edge.first;
                int color = edge.second;

                // Must alternate colors
                if (color == lastColor) continue;

                // Already visited with this incoming color?
                if (visited[nxt][color]) continue;

                visited[nxt][color] = 1;

                if (res[nxt] == -1)
                    res[nxt] = steps + 1;

                q.push({nxt, steps + 1, color});
            }
        }

        return res;
    }
};
