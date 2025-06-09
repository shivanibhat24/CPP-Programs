class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (d > n) {
            return -1;
        }
        vector dp = vector(d, vector(n, INT_MAX));
        dp[0][0] = jobDifficulty[0];
        for (int job = 1; job <= n - d; ++job) {
            dp[0][job] = std::max(dp[0][job - 1], jobDifficulty[job]);
        }
        for (int day = 1; day < d; ++day) {
            dp[day][day] = dp[day - 1][day - 1] + jobDifficulty[day];
            for (int job = day + 1; job <= n - d + day; ++job) {
                int difficulty = jobDifficulty[job];
                int prevJob;
                for (prevJob = job - 1; prevJob >= day - 1; --prevJob) {
                    dp[day][job] = std::min(dp[day][job],
                                            dp[day - 1][prevJob] + difficulty);
                    if (jobDifficulty[prevJob] > difficulty) {
                        --prevJob;
                        break;
                    }
                }
                ++prevJob;
                dp[day][job] = std::min(dp[day][prevJob], dp[day][job]);
            }
        }
        return dp[d - 1][n - 1];
    }
};
