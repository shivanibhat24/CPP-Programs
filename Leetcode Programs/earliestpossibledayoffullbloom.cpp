class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> seeds(n);
        for (int i = 0; i < n; ++i)
            seeds[i] = {plantTime[i], growTime[i]};
        sort(seeds.begin(), seeds.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; });
        int currentDay = 0, maxBloomDay = 0;
        for (auto& [plant, grow] : seeds) {
            currentDay += plant;
            maxBloomDay = max(maxBloomDay, currentDay + grow);
        }
        return maxBloomDay;
    }
};
