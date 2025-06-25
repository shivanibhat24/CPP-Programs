class Solution {
using pif = std::pair<int,float>;
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        std::vector<pif> arrival_times;
        arrival_times.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            auto pos = position[i];
            auto time = static_cast<float>(target - pos) / speed[i];
            arrival_times.emplace_back(pos, time);
        }
        std::sort(arrival_times.begin(), arrival_times.end(), std::greater<pif>());
        int fleets = 1;
        for (int i = 1; i < n; ++i)
        {
            if (arrival_times[i].second > arrival_times[i-1].second)
            {
                ++fleets;
            }
            else
            {
                arrival_times[i].second = arrival_times[i-1].second;
            }
        }
        return fleets;
    }
};
