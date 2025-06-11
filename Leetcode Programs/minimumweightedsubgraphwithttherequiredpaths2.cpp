const int MAX_NODES_GLOBAL = 100000 + 5; 
std::vector<std::pair<int, int>> adj_global[MAX_NODES_GLOBAL];
long long dist_from_root_global[MAX_NODES_GLOBAL];
int parent_global[MAX_NODES_GLOBAL];
int depth_global[MAX_NODES_GLOBAL];
int subtree_size_global[MAX_NODES_GLOBAL];
int heavy_child_global[MAX_NODES_GLOBAL];
int path_head_global[MAX_NODES_GLOBAL];
void hld_dfs1(int u, int p, int d, long long current_dist_w, int n_nodes) {
    parent_global[u] = p;
    depth_global[u] = d;
    dist_from_root_global[u] = current_dist_w;
    subtree_size_global[u] = 1;
    int max_c_subtree_size = 0;
    for (auto& edge : adj_global[u]) {
        int v = edge.first;
        int weight = edge.second;
        if (v == p) continue;        
        hld_dfs1(v, u, d + 1, current_dist_w + weight, n_nodes);
        subtree_size_global[u] += subtree_size_global[v];        
        if (subtree_size_global[v] > max_c_subtree_size) {
            max_c_subtree_size = subtree_size_global[v];
            heavy_child_global[u] = v;
        }
    }
}
void hld_dfs2(int u, int p, int head_node, int n_nodes) {
    path_head_global[u] = head_node;
    if (heavy_child_global[u] != -1) {
        hld_dfs2(heavy_child_global[u], u, head_node, n_nodes);
    }
    for (auto& edge : adj_global[u]) {
        int v = edge.first;
        if (v == p || v == heavy_child_global[u]) continue;
        hld_dfs2(v, u, v, n_nodes); 
    }
}
int get_lca_hld(int u, int v) {
    while (path_head_global[u] != path_head_global[v]) {
        if (depth_global[path_head_global[u]] < depth_global[path_head_global[v]]) {
            std::swap(u, v);
        }
        u = parent_global[path_head_global[u]]; 
    }
    return depth_global[u] < depth_global[v] ? u : v;
}
long long get_path_dist_hld(int u, int v) {
    int lca_node = get_lca_hld(u, v);
    return dist_from_root_global[u] + dist_from_root_global[v] - 2 * dist_from_root_global[lca_node];
}
class Solution {
public:
    std::vector<int> minimumWeight(std::vector<std::vector<int>>& edges_input, std::vector<std::vector<int>>& queries_input) {
        int n = edges_input.size() + 1;
        for (int i = 0; i < n; ++i) {
            adj_global[i].clear();
            heavy_child_global[i] = -1; 
        }
        for (const auto& edge : edges_input) {
            adj_global[edge[0]].push_back({edge[1], edge[2]});
            adj_global[edge[1]].push_back({edge[0], edge[2]});
        }
        hld_dfs1(0, 0, 0, 0LL, n); 
        hld_dfs2(0, 0, 0, n);
        std::vector<int> answers;
        answers.reserve(queries_input.size());
        for (const auto& query : queries_input) {
            int s1 = query[0];
            int s2 = query[1];
            int d = query[2];
            long long d_s1_s2 = get_path_dist_hld(s1, s2);
            long long d_s1_d = get_path_dist_hld(s1, d);
            long long d_s2_d = get_path_dist_hld(s2, d);
            long long total_sum_dist = d_s1_s2 + d_s1_d + d_s2_d;
            answers.push_back(static_cast<int>(total_sum_dist / 2));
        }
        return answers;
    }
};
