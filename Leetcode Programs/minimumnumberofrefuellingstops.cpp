class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int fuel_available = startFuel;
        int cnt = 0;
        int prev_location = 0;
        for(int i = 0; i < n; i++) {
            int cur_location = stations[i][0], fuel_here = stations[i][1];
            while(!pq.empty() && cur_location - prev_location > fuel_available) {
                fuel_available += pq.top(); pq.pop();
                cnt++;
            }
            if(cur_location - prev_location > fuel_available) {
                cout << "i\n";
                return -1;
            }
            fuel_available -= (cur_location - prev_location);
            prev_location = cur_location;
            pq.emplace(fuel_here);
        }
        prev_location += fuel_available;
        while(!pq.empty() && target > prev_location) {
            cnt++;
            prev_location += pq.top(); pq.pop();
        }
        return (target <= prev_location) ? cnt : -1;
    }
};
