typedef tuple<int, uint32_t, uint32_t> T;
class Solution {
public:
    uint32_t parents[1000];
    int rank_parents[1000] = {};

    uint32_t parent(uint32_t node) {
        if(parents[parents[node]] != parents[node]) {
            parents[node] = parent(parents[node]);
        }
        return parents[node];
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        const uint32_t m = matrix.size();
        const uint32_t n = matrix[0].size();
        const uint32_t sz = n * m;
        vector<T> sorted;
        sorted.reserve(sz);
        // compute row rank
        for(uint32_t i = 0; i < m; i++) {
            for(uint32_t j = 0; j < n; j++) {
                sorted.push_back({matrix[i][j], i, j}); 
            }
        }
        sort(sorted.begin(), sorted.end(), [&](const T& a, const T& b) { return get<0>(a) < get<0>(b); }); 
        uint32_t ptr = 0;
        while(ptr < sz) {
            size_t cluster = ptr;
            int target = get<0>(sorted[ptr]);
            // fast path
            if(ptr + 1 < sz && get<0>(sorted[ptr + 1]) != target) {
                auto [value, y, x] = sorted[ptr];
                int rank = max(rank_parents[y], rank_parents[m + x]) + 1;
                matrix[y][x] = rank;
                rank_parents[y] = matrix[y][x];
                rank_parents[m + x] = matrix[y][x];
                ptr++;
                continue;
            }
            iota(parents, parents + m + n, 0);
            // first pass to scan and assign groups
            while(cluster < sz && get<0>(sorted[cluster]) == target) {
                auto [value, y, x] = sorted[cluster];
                int p_row = parent(y);
                int p_col = parent(m + x);
                if(p_row != p_col) {
                    parents[p_col] = p_row;
                    rank_parents[p_row] = max(rank_parents[p_row], rank_parents[p_col]); 
                }
                get<0>(sorted[cluster]) = p_row;
                cluster++;
            }
            uint32_t write = ptr;
            while(write < cluster) {
                auto [value, y, x] = sorted[write];
                int rank = rank_parents[parent(get<0>(sorted[write]))] + 1;
                matrix[y][x] = rank;
                write++;
            }
            write = ptr;
            while(write < cluster) {
                auto [value, y, x] = sorted[write];
                rank_parents[y] = matrix[y][x];
                rank_parents[m + x] = matrix[y][x];
                write++;
            }
            ptr = cluster;
        }
        return matrix;
    }
};
