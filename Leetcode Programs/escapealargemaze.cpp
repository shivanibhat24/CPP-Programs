class Solution {
  int grid[500][500];
  int end_j = 1'000'000;
  int end_i = 1'000'000;
  void dfs(const int i, const int j) {
    if (i < 0 || j < 0 || i > end_i || j > end_j) return;
    if (grid[i][j] != 0) return;
    grid[i][j] = 2;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
  }
 public:
  bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                        vector<int>& target) {
    vector<pair<int, int>> xs, ys;
    xs.emplace_back(source.front(), -1);
    ys.emplace_back(source.back(), -1);
    xs.emplace_back(target.front(), -2);
    ys.emplace_back(target.back(), -2);
    xs.emplace_back(end_j, -3);
    ys.emplace_back(end_i, -3);
    xs.emplace_back(0, -4);
    ys.emplace_back(0, -4);
    for (size_t i = 0; i < blocked.size(); i++) {
      xs.emplace_back(blocked[i].front(), i);
      ys.emplace_back(blocked[i].back(), i);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    int curr_x = 0;
    int x = xs.front().first;
    for (const auto& [x0, idx] : xs) {
      curr_x += min(abs(x0 - x), 2);
      x = x0;

      if (idx == -1) {
        source.front() = curr_x;
      } else if (idx == -2) {
        target.front() = curr_x;
      } else if (idx == -3) {
        end_j = curr_x;
      } else if (idx >= 0) {
        blocked[idx].front() = curr_x;
      }
    }
    int curr_y = 0;
    int y = ys.front().first;
    for (const auto& [y0, idx] : ys) {
      curr_y += min(abs(y0 - y), 2);
      y = y0;
      if (idx == -1) {
        source.back() = curr_y;
      } else if (idx == -2) {
        target.back() = curr_y;
      } else if (idx == -3) {
        end_i = curr_y;
      } else if (idx >= 0) {
        blocked[idx].back() = curr_y;
      }
    }
    memset(grid, 0, sizeof grid);
    for (const vector<int>& vec : blocked) {
      grid[vec.front()][vec.back()] = 1;
    }
    dfs(source.front(), source.back());
    return grid[target.front()][target.back()] == 2;
  }
};
