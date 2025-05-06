class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> dist(1002, 0);
        for (auto &trip : trips) {
            dist[trip[1]] += trip[0];
            dist[trip[2]] -= trip[0];
        }
        int currPassengers = 0;
        for (int passengers : dist) {
            currPassengers += passengers;
            if (currPassengers > capacity) return false;
        }
        return true;
    }
};
