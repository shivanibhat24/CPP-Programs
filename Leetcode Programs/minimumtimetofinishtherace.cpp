int MinFinishTime(const vector<vector<int>>& tires, int laps, int change_time,
                  const vector<int>& min_time_with_tire, vector<int>& memo,
                  bool is_first_lap = true) {
  if (laps == 0) {
    return 0;
  }
  if (memo[laps - 1] != -1) {
    return memo[laps - 1];
  }
  int result = numeric_limits<int>::max();
  int c = is_first_lap ? 0 : change_time;
  for (int i = 0; i < min((int)min_time_with_tire.size(), laps); ++i) {
    result = min(c + min_time_with_tire[i] +
                     MinFinishTime(tires, laps - i - 1, change_time,
                                   min_time_with_tire, memo, false),
                 result);
  }
  return memo[laps - 1] = result;
}
class Solution {
 public:
  int minimumFinishTime(vector<vector<int>>& tires, int change_time, int laps) {
    vector<int> min_time_with_tire;
    for (auto& t : tires) {
      int lap_time = t[0];
      int time_with_tire = 0;
      for (int lap = 0; lap < laps; ++lap) {
        time_with_tire += lap_time;
        if (lap == min_time_with_tire.size()) {
          min_time_with_tire.push_back(time_with_tire);
        } else {
          min_time_with_tire[lap] =
              min(time_with_tire, min_time_with_tire[lap]);
        }
        if (lap_time > (t[0] + change_time) / t[1]) {
          break;
        }
        lap_time *= t[1];
      }
    }
    vector<int> memo(laps, -1);
    return MinFinishTime(tires, laps, change_time, min_time_with_tire, memo);
  }
};
