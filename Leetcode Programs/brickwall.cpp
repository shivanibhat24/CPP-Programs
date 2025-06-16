class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> countGap;
        countGap[0] = 0;
        for(int i = 0; i < wall.size(); i++)
        {
            long long curr = 0;
            for(int j = 0; j < wall[i].size() - 1; j++)
            {
                curr += wall[i][j];
                countGap[curr]++;
            }
        }
        int maxGaps = 0;
        for(auto [pos, count] : countGap)
        {
            maxGaps = max(maxGaps, count);
        }
        return wall.size() - maxGaps;
    }
};
