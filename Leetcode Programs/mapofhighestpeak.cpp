class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int rows = isWater.size();
        const int cols = isWater[0].size();
        const int INF = rows * cols;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                isWater[row][col] = isWater[row][col] == 0 ? INF : 0;
            }
        }
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int mnd = INF;
                if (row - 1 >= 0) mnd = min(mnd, isWater[row-1][col]);
                if (col - 1 >= 0) mnd = min(mnd, isWater[row][col-1]);
                isWater[row][col] = min(isWater[row][col], mnd + 1);
            }
        }
        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                int mnd = INF;
                if (row + 1 < rows) mnd = min(mnd, isWater[row+1][col]);
                if (col + 1 < cols) mnd = min(mnd, isWater[row][col+1]);
                isWater[row][col] = min(isWater[row][col], mnd + 1);
            }
        }
        return isWater;
    }
};
