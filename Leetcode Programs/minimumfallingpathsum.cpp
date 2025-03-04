class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) memo[0][i] = matrix[0][i];
        for (int i = 1; i < n; i++) 
            for (int j = 0; j < n; j++) {
                int left = (j > 0) ? memo[i-1][j-1] : INT_MAX;
                int right = (j < n-1) ? memo[i-1][j+1] : INT_MAX;
                int up = memo[i-1][j];
                memo[i][j] = matrix[i][j] + min(up, min(left, right));
            }
        int result = INT_MAX;
        for (int i = 0; i < n; i++) result = min(result, memo[n-1][i]);
        return result;
    }
};
