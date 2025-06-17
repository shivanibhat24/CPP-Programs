class Solution {
    int row;
    int colm;
    int get_area(vector<vector<int>>& grid, int i, int j) {
        int A = 0;
        if (i >= 0 && i < row && j>=0 && j<colm && grid[i][j]==1) {
            grid[i][j] = 0;
            A = 1;
            A += get_area(grid, i-1, j);
            A += get_area(grid, i+1, j);
            A += get_area(grid, i, j-1);
            A += get_area(grid, i, j+1);
        }
        return A;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        colm = grid[0].size();
        int max_area = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < colm; j++) {
                int curr_area = get_area(grid, i, j);
                if (max_area < curr_area) max_area = curr_area;
            }
        }
        return max_area;
    }
};
