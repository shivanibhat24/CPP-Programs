class Solution {
public:
    void print_table(vector<vector<int>> const &table) {
        for (int split_begin = 0; split_begin < table.size(); ++split_begin) {
            for (int split_end = 0; split_end < table[0].size(); ++split_end) {
                std::cout << table[split_begin][split_end] << " ";
            }
            cout << endl;
        }
        cout << string(table[0].size(), '-') << endl;
    }
    int palindromePartition(string s, int k) {
        int n = s.length();
        int n_splits = k;
        vector<vector<int>> cost_table(n, vector<int>(n, 0));
        for (int twice_split_center = 0; twice_split_center < (n * 2 - 1); ++twice_split_center) {
            bool even_n_elements = true;
            if (twice_split_center % 2 == 0) {
                even_n_elements = false;
            }
            int first_split_size = even_n_elements ? 2 : 1; 
            int max_n_elements = n * 2 - twice_split_center;            
            int cost = 0;
            for (int split_size = first_split_size; split_size <= min(twice_split_center + 1, max_n_elements); split_size += 2) {
                int split_begin = int((twice_split_center + 1) / 2) - int(split_size / 2);
                int split_end = int((twice_split_center) / 2) + int(split_size / 2);
                bool matches = s[split_begin] == s[split_end];
                cost = cost + (matches ? 0 : 1);
                cost_table[split_begin][split_end] = cost;
            }
        }
        vector<vector<int>> table(k, vector<int>(n, INT_MAX));
        for (int split = 0; split < n_splits; ++split) {
            for (int split_begin = split; split_begin < (split ? (n - n_splits + 1 + split) : 1); ++split_begin) {
                int end = (n - n_splits + 1 + split);
                for (int split_end = (split == n_splits - 1) ? (end - 1) : split_begin ; split_end < end; ++split_end) {
                    int cost = 0;
                    if (split > 0) {
                        cost += table[split - 1][split_begin - 1];
                    }
                    cost += cost_table[split_begin][split_end];
                    if (cost < table[split][split_end]) {
                        table[split][split_end] = cost;
                    } 
                }
            }
        }
        return table[n_splits-1][n-1];
    }
};
