class MyCalendarTwo {
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        for(auto& [s, e] : overlaps) {
            if(max(s, start) < min(e, end)) {
                return false;
            }
        }
        for(auto& [s, e] : booked) {
            if(max(s, start) < min(e, end)) {
                overlaps.push_back({max(s, start), min(e, end)});
            }
        }
        booked.push_back({start, end});
        return true;
    }
};
