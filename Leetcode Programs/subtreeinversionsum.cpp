class Solution {
public:
    long subtreeInversionSum(const vector<vector<int>>& edges, const vector<int>& nums, int k) {
        const size_t sz = nums.size();
        vector<vector<int>> graph(sz);
        for(const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<tuple<int, long, long>> parents = {{-1,0,0}};
        auto [total, pos, neg] = process(graph, parents, nums, k, 0);
        return pos + total;
    }
    tuple<long, long, long> process(const vector<vector<int>>& graph, vector<tuple<int, long, long>>& parents, const vector<int>& nums, int k, int node) {
        long subtree = nums[node];
        long total_pos = 0;
        long total_neg = 0;
        int parent = get<0>(parents.back());
        parents.push_back({node, 0, 0});
        for(int child: graph[node]) {
            if(child == parent) {
                continue;
            }
            auto [sum, pos, neg] = process(graph, parents, nums, k, child);
            subtree += sum;
            total_pos += pos;
            total_neg += neg;
        }
        total_pos = max(total_pos, get<1>(parents.back()) - 2 * subtree); 
        total_neg = max(total_neg, get<2>(parents.back()) + 2 * subtree); 
        parents.pop_back();
        if(parents.size() > k) {
            get<1>(parents[parents.size() - k]) += total_neg;
            get<2>(parents[parents.size() - k]) += total_pos;
        }
        return {subtree, total_pos, total_neg};  
    }
};
