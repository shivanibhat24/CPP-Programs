class MyCalendar {
public:
    MyCalendar() {        
    }    
    bool book(int startTime, int endTime) {
        auto left = pairs.lower_bound({startTime, endTime});
        if (left != pairs.end() && left->first < endTime) return false;
        if (left != pairs.begin() && startTime < (--left)->second) return false;
        pairs.insert({startTime, endTime});
        return true;
    }
    set<pair<int, int>> pairs{};
};
