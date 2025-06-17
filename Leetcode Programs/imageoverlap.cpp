class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int rows = img1.size();
        int cols = img1[0].size();
        vector<pair<int, int>> pt1, pt2;
        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < cols; ++x) {
                if (img1[y][x])
                    pt1.push_back(make_pair<>(x, y));
                if (img2[y][x])
                    pt2.push_back(make_pair<>(x, y));
            }
        }
        int o = 0;
        vector<int> m(cols * rows * 4, 0);
        for (auto p1: pt1) {
            for(auto p2: pt2) {
                int offset = (p2.second - p1.second + rows) * cols * 2 + p2.first - p1.first + cols;
                if (++m[offset] > o) {
                    o = m[offset];
                }
            }
        }
        return o;
    }
};
