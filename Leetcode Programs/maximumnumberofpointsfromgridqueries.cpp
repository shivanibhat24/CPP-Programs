#include <ranges>

static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    auto ans = vector<int>(size(queries));

    if (ranges::all_of(queries, [start=grid[0][0]](auto query) {
                                  return query <= start; })) {
      return ans;
    }

    auto sorted_query_indexes = vector<pair<int, int>>{};
    sorted_query_indexes.reserve(size(queries));
    for (auto [i, query] : views::enumerate(queries)) {
      sorted_query_indexes.emplace_back(query, i);
    }
    ranges::sort(sorted_query_indexes);

    auto q = queue<pair<int, int>>{};
    auto frontier = priority_queue(greater{},
      vector<tuple<int, int, int>>{{grid[0][0], 0, 0}});
    grid[0][0] = 0;
    auto score = 0;
    auto m = size(grid);
    auto n = size(grid[0]);

    for (auto [query, query_idx] : sorted_query_indexes) {
      while (!empty(frontier) && get<0>(frontier.top()) < query) {
        auto [_, i, j] = frontier.top();
        frontier.pop();
        q.emplace(i, j);
      }
      while (!empty(q)) {
        auto [i, j] = q.front();
        q.pop();
        ++score;
        if (i > 0 && grid[i - 1][j]) {
          if (grid[i - 1][j] < query) {
            q.emplace(i - 1, j);
          } else {
            frontier.emplace(grid[i - 1][j], i - 1, j);
          }
          grid[i - 1][j] = 0;
        }
        if (i < m - 1 && grid[i + 1][j]) {
          if (grid[i + 1][j] < query) {
            q.emplace(i + 1, j);
          } else {
            frontier.emplace(grid[i + 1][j], i + 1, j);
          }
          grid[i + 1][j] = 0;
        }
        if (j > 0 && grid[i][j - 1]) {
          if (grid[i][j - 1] < query) {
            q.emplace(i, j - 1);
          } else {
            frontier.emplace(grid[i][j - 1], i, j - 1);
          }
          grid[i][j - 1] = 0;
        }
        if (j < n - 1 && grid[i][j + 1]) {
          if (grid[i][j + 1] < query) {
            q.emplace(i, j + 1);
          } else {
            frontier.emplace(grid[i][j + 1], i, j + 1);
          }
          grid[i][j + 1] = 0;
        }
      }
      ans[query_idx] = score;
    }
    return ans;
  }
};
