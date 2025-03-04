class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> next(n, 0), curr(n, 0);
        for (int j = 0; j < n; j++) {
            next[j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + next[j];
                int diagonal = triangle[i][j] + next[j + 1];
                curr[j] = min(down, diagonal);
            }
            next = curr;
        }
        return next[0];
    }
};
