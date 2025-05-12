class Solution {
    static constexpr int DIR[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    struct Cell {
        short r : 8;
        short c : 8;
    };
    int doit(const vector<vector<int>>& forest, Cell start, vector<int> &curr, vector<int> &prev, vector<Cell> &bfs) {
        const int M = forest.size(), N = forest[0].size();
        int steps = 0;
        swap(curr, prev);
        fill(begin(curr), end(curr), -1);
        curr[start.r * N + start.c] = steps;
        if (prev[start.r * N + start.c] != -1) {
            return prev[start.r * N + start.c];
        }
        bfs.clear();
        bfs.push_back(start);
        while (!bfs.empty()) {
            int size = bfs.size();
            steps++;
            while (size--) {
                auto [r0, c0] = bfs[size];
                swap(bfs[size], bfs.back());
                bfs.pop_back();
                for (auto [dr, dc] : DIR) {
                    short r1 = r0 + dr, c1 = c0 + dc;
                    int pos = r1 * N + c1;
                    if (r1 >= 0 && r1 < M && c1 >= 0 && c1 < N && forest[r1][c1] > 0 && curr[pos] == -1) {
                        if (prev[pos] != -1) {
                            return steps + prev[pos];
                        }
                        curr[pos] = steps;
                        bfs.push_back({r1, c1});
                    }
                }
            }
        }
        return -1;
    }
    int manhattan_distance(vector<Cell> &cells) {
        int result = 0;
        Cell prev{0, 0};
        for (auto &cell : cells) {
            result += abs(prev.r - cell.r) + abs(prev.c - cell.c);
            prev = cell;
        }
        return result;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        const int M = forest.size(), N = forest[0].size();
        if (forest[0][0] == 0) {
            return -1;
        }
        int obstacles = 0;
        vector<Cell> cells;
        cells.reserve(8);

        for (short r = 0; r < M; r++) {
            for (short c = 0; c < N; c++) {
                if (forest[r][c] > 1) {
                    cells.push_back({r, c});
                } else if (forest[r][c] == 0) {
                    obstacles++;
                }
            }
        }
        sort(begin(cells), end(cells), [&forest](const Cell &a, const Cell &b){
            return forest[a.r][a.c] < forest[b.r][b.c];
        });
        if (obstacles == 0) {
            return manhattan_distance(cells);
        }
        vector<int> curr(M * N, -1), prev = curr;
        curr[0] = 0;
        vector<Cell> bfs;
        bfs.reserve(8);
        int steps = 0;
        for (auto &cell : cells) {
            int result = doit(forest, cell, curr, prev, bfs);
            if (result != -1) {
                steps += result;
            } else {
                return -1;
            }
        }
        return steps;
    }
};
