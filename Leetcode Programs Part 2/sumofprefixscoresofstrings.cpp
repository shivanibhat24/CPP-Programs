class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        std::vector<int> sorted;
        for(int i = 0; i < words.size(); ++i) {
            sorted.push_back(i);
        }
        std::sort(sorted.begin(), sorted.end(), [&words](const auto& a, const auto& b) { return words[a] < words[b]; });

        std::vector<std::pair<int, int>> last;
        std::vector<int> result(words.size());

        for(int i = 0; i < sorted.size(); ++i) {
            auto w = words[sorted[i]];
            for(int j = 0; j < w.size(); ++j) {
                if (j >= last.size() || w[j] != words[sorted[i - 1]][j]) {
                    last.resize(j);
                    auto it = std::upper_bound(
                        sorted.begin() + i,
                        j == 0 ? sorted.end() : sorted.begin() + last.back().first + last.back().second,
                        w,
                        [j, &words](auto& a, auto& b) {
                            int size_a = min(j + 1, static_cast<int>(a.size()));
                            int size_b = min(j + 1, static_cast<int>(words[b].size()));
                            return size_b < size_a 
                                || size_b == size_a && a[j] < words[b][j];
                        }
                    );
                    last.push_back({std::distance(sorted.begin() + i, it), i});
                }
                result[sorted[i]] += last[j].first;   
            }
        }
        return result;
    }
};
