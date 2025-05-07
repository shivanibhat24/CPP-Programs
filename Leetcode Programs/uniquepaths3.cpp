class Solution {
public:
    int helper(int r, int c, int visited) {
        int answer = 0;
        for (int i = 0; i < 4; ++i) {
            int rNew = r + dr[i];
            int cNew = c + dc[i];
            if (0 > rNew || 0 > cNew || rNew >= rows || cNew >= cols)
            {
                continue;
            }
            if (visited & (1 << (rNew * cols + cNew))) {
                continue;
            }
            auto visitedUpdated = visited | (1 << (rNew * cols + cNew));
            if (grid[rNew][cNew] == 2) { 
                answer += (visitedUpdated + 1 == 1 << (rows*cols));
            }
            answer += helper(rNew, cNew, visitedUpdated);
        }
        return answer;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        this->grid = std::move(grid);
        int visited = 0;
        int startR, startC;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (this->grid[i][j] == -1) {
                    visited |= (1 << (i * cols + j));
                }
                if (this->grid[i][j] == 1) {
                    startR = i;
                    startC = j;
                    visited |= (1 << (i * cols + j));
                }
            }
        }
        return helper(startR, startC, visited);
    }
private:
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };
    int rows, cols;
    vector<vector<int>> grid;
};
