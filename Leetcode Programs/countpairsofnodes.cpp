class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges,
                           vector<int>& queries) {
        vector<int> node_degrees(n);
        unordered_map<int, int> edge_freq;
        for (auto& e : edges) {
            sort(begin(e), end(e));
            ++node_degrees[--e[0]];
            ++node_degrees[--e[1]];
            ++edge_freq[(e[0] << 16) | e[1]];
        }
        const int max_degree =
            *max_element(begin(node_degrees), end(node_degrees));
        vector<int> counts(max_degree * 2 + 2);
        unordered_map<int, int> degree_count;
        for (int i = 0; i < n; ++i)
            ++degree_count[node_degrees[i]];
        for (auto& [d1, c1] : degree_count)
            for (auto& [d2, c2] : degree_count)
                if (d1 < d2)
                    counts[d1 + d2] += c1 * c2;
                else if (d1 == d2)
                    counts[d1 * 2] += c1 * (c1 - 1) / 2;
        for (auto& [key, freq] : edge_freq) {
            const int u = key >> 16;
            const int v = key & 0xFFFF;
            counts[node_degrees[u] + node_degrees[v]] -= 1;
            counts[node_degrees[u] + node_degrees[v] - freq] += 1;
        }
        for (int i = counts.size() - 2; i >= 0; --i)
            counts[i] += counts[i + 1];
        vector<int> ans;
        for (int q : queries)
            ans.push_back(
                counts[min(q + 1, static_cast<int>(counts.size() - 1))]);
        return ans;
    }
};
