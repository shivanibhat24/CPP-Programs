class Solution {
public:
    static int networkDelayTime(const std::vector<std::vector<int>>& times,
                         const uint32_t n, const uint32_t k) {
        struct Edge {
            uint32_t dst_node = 0;
            uint32_t distance = 0;
        };
        std::vector<Edge> output_edges[n];
        for (const auto& edge : times)
            output_edges[edge[0] - 1].push_back(
                Edge{uint32_t(edge[1] - 1), uint32_t(edge[2])});
        uint32_t distance_table[n];
        for (uint32_t& i : distance_table)
            i = std::numeric_limits<uint32_t>::max();
        distance_table[k - 1] = 0;
        struct Item {
            uint32_t node = 0;
            uint32_t distance = 0;
        };
        const auto compare = [](const Item& l, const Item& r) {
            return l.distance > r.distance;
        };
        std::vector<Item> heap;
        heap.push_back(Item{k - 1, 0});
        while (!heap.empty()) {
            const Item item = heap.front();
            std::pop_heap(heap.begin(), heap.end(), compare);
            heap.pop_back();
            for (const Edge& edge : output_edges[item.node]) {
                const uint32_t distance = item.distance + edge.distance;
                uint32_t& prev_distance= distance_table[edge.dst_node];
                if (prev_distance <= distance)
                    continue;
                prev_distance = distance;
                heap.push_back(Item{edge.dst_node, distance});
                std::push_heap(heap.begin(), heap.end(), compare);
            }
        }
        uint32_t max_distance = 0;
        for (const uint32_t d : distance_table) {
            if (d > max_distance)
                max_distance = d;
        }
        return max_distance == std::numeric_limits<uint32_t>::max() ? int(-1)
                                                               : int(max_distance);
    }
};
