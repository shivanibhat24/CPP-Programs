class Solution {
public:
    int findNext(vector<int>& parent, int day) {
        if (day >= parent.size()) return 0; 
        if (parent[day] == day) return day;
        return parent[day] = findNext(parent, parent[day]);
    }
    int maxEvents(vector<vector<int>>& events) {
        vector<pair<int,int>> arr1;
        for (auto &e : events) arr1.push_back({e[1], e[0]});
        sort(arr1.begin(), arr1.end());
        int maxDay = 0;
        for (auto &p : arr1) maxDay = max(maxDay, p.first);
        vector<int> parent(maxDay + 2);
        for (int i = 0; i <= maxDay + 1; i++) parent[i] = i;
        int e = 0;
        for (auto &p : arr1) {
            int day = findNext(parent, p.second);
            if (day && day <= p.first) {
                e++;
                parent[day] = findNext(parent, day + 1); 
            }
        }
        return e;
    }
};
