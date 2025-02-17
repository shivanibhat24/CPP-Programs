class Solution {
public:
    int maxScore(std::vector<std::vector<int>>& grid) {
        if(grid.size() <= 0){
            return -1;
        }
        for(auto& r : grid){
            std::sort(r.begin(), r.end());
            r.erase(std::unique(r.begin(), r.end()), r.end());
            std::reverse(r.begin(), r.end());
        }
        const int m = grid.size();
        bool slow_case = true && (m >= 10);
        for(const auto& r : grid){
            slow_case = slow_case && r == grid[0];
        }
        if(slow_case){
            return std::accumulate(grid[0].begin(), grid[0].end(), 0);
        }
        int best = 0;
        bool included_values_set[1001];
        std::fill(included_values_set, included_values_set + 1001, false);
        std::vector<int> partial(m);
        for(int i = m - 1, cumulative = 0; i >= 0; --i){
            cumulative += grid[i][0];
            partial[i] = cumulative;
        }
        const auto backtrack =
            [&best, &included_values_set, &m, &grid, &partial]
            (const int row_index, const int total, const auto& f){
            if(row_index >= m){
                best = std::max(best, total);
                return;
            }
            if(best > (total + partial[row_index])){
                return;
            }
            const auto& curr_row = grid[row_index];
            bool all_pruned = true;
            for(std::size_t i = 0; i < curr_row.size(); ++i){
                const int value_at_i = curr_row[i];
                if(!included_values_set[value_at_i]){
                    included_values_set[value_at_i] = true;
                    f(row_index + 1, total + value_at_i, f);
                    included_values_set[value_at_i] = false;
                    all_pruned = false;
                }
            }
            if(all_pruned){
                f(row_index + 1, total, f);
            }
        };
        backtrack(0, 0, backtrack);
        return best;
    }
};
