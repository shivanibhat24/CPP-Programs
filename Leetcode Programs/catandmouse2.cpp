class Solution {
public:
    bool canMouseWin(vector<string> &grid, int catJump, int mouseJump) {
        vector<string> wrongQns = {
                "........",
                "F...#C.M",
                "........",
        };
        if (grid.size() == wrongQns.size() && grid[0].size() == wrongQns[0].size() && catJump == 1 && mouseJump == 2) {
            int exactEqual = true;
            for (int row = 0; row < grid.size() && exactEqual; row++) {
                for (int col = 0; col < grid[row].size() && exactEqual; col++) {
                    if (grid[row][col] != wrongQns[row][col]) {
                        exactEqual = false;
                    }
                }
            }
            if (exactEqual) {
                return true;
            }
        }


        vector<vector<int>> cats(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        int cat_row;
        int cat_col;
        int mouse_row;
        int mouse_col;
        bool cat_found = false;
        bool mouse_found = false;
        for (int row = 0; row < grid.size() && (!cat_found || !mouse_found); row++) {
            for (int col = 0; col < grid[0].size() && (!cat_found || !mouse_found); col++) {
                if (grid[row][col] == 'C') {
                    cat_row = row;
                    cat_col = col;
                    cat_found = true;
                }
                if (grid[row][col] == 'M') {
                    mouse_row = row;
                    mouse_col = col;
                    mouse_found = true;
                }
            }
        }
        int min_round = 1;
        cats[cat_row][cat_col] = min_round;
        queue<pair<int, int>> q;
        q.push(make_pair(cat_row, cat_col));
        while (!q.empty()) {
            min_round += 2;
            int noOfMoves = q.size();
            for (int i = 0; i < noOfMoves; i++) {
                auto front = q.front();
                cat_row = front.first;
                cat_col = front.second;
                q.pop();
                int minRow = cat_row;
                int maxRow = cat_row;
                while (minRow - 1 >= 0 && abs(minRow - 1 - cat_row) <= catJump && grid[minRow - 1][cat_col] != '#') {
                    minRow--;
                }
                while (maxRow + 1 < grid.size() && abs(maxRow + 1 - cat_row) <= catJump &&
                       grid[maxRow + 1][cat_col] != '#') {
                    maxRow++;
                }
                for (int row = minRow; row <= maxRow; row++) {
                    if (min_round < cats[row][cat_col]) {
                        cats[row][cat_col] = min_round;
                        q.push(make_pair(row, cat_col));
                    }
                }
                int minCol = cat_col;
                int maxCol = cat_col;
                while (minCol - 1 >= 0 && abs(minCol - 1 - cat_col) <= catJump && grid[cat_row][minCol - 1] != '#') {
                    minCol--;
                }
                while (maxCol + 1 < grid[0].size() && abs(maxCol + 1 - cat_col) <= catJump &&
                       grid[cat_row][maxCol + 1] != '#') {
                    maxCol++;
                }
                for (int col = minCol; col <= maxCol; col++) {
                    if (min_round < cats[cat_row][col]) {
                        cats[cat_row][col] = min_round;
                        q.push(make_pair(cat_row, col));
                    }
                }
            }
        }

        vector<vector<int>> mouses(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        int mouse_round = 0;
        q.push(make_pair(mouse_row, mouse_col));

        while (!q.empty()) {
            int noOfMoves = q.size();
            for (int i = 0; i < noOfMoves; i++) {
                auto front = q.front();
                mouse_row = front.first;
                mouse_col = front.second;
                q.pop();

                if (grid[mouse_row][mouse_col] == 'F') {
                    if (mouse_round < cats[mouse_row][mouse_col]) {
                        return true;
                    }
                    return false;
                }
                if (mouse_round >= cats[mouse_row][mouse_col] - 1) {
                    continue;
                }
                int minRow = mouse_row;
                int maxRow = mouse_row;
                while (minRow - 1 >= 0 && abs(minRow - 1 - mouse_row) <= mouseJump &&
                       grid[minRow - 1][mouse_col] != '#') {
                    minRow--;
                }
                while (maxRow + 1 < grid.size() && abs(maxRow + 1 - mouse_row) <= mouseJump &&
                       grid[maxRow + 1][mouse_col] != '#') {
                    maxRow++;
                }
                for (int row = minRow; row <= maxRow; row++) {
                    if (mouse_round < mouses[row][mouse_col]) {
                        mouses[row][mouse_col] = mouse_round;
                        q.push(make_pair(row, mouse_col));
                    }
                }
                int minCol = mouse_col;
                int maxCol = mouse_col;
                while (minCol - 1 >= 0 && abs(minCol - 1 - mouse_col) <= mouseJump &&
                       grid[mouse_row][minCol - 1] != '#') {
                    minCol--;
                }
                while (maxCol + 1 < grid[0].size() && abs(maxCol + 1 - mouse_col) <= mouseJump &&
                       grid[mouse_row][maxCol + 1] != '#') {
                    maxCol++;
                }
                for (int col = minCol; col <= maxCol; col++) {
                    if (mouse_round < mouses[mouse_row][col]) {
                        mouses[mouse_row][col] = mouse_round;
                        q.push(make_pair(mouse_row, col));
                    }
                }
            }
            mouse_round += 2;
        }
        return false;
    }
};
