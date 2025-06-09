class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(begin(tasks), end(tasks), [](const auto& a, const auto& b) {
            return a[1] - a[0] < b[1] - b[0];
        });
        int res{0};
        for (const auto& task : tasks) {
            res = max(res + task[0], task[1]);
        }
        return res;
    }
};
