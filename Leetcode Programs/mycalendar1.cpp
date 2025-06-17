class MyCalendar {
public:
    unordered_set<int> m; 
    MyCalendar() {}
    bool book(int start, int end) {
        unordered_set<int> subset;
        for (int i = start; i < end; i++) {
            if (m.count(i) > 0) { 
                return false;
            }
            subset.insert(i);
        }
        for (auto x : subset) { 
            m.insert(x);
        }
        return true;
    }
};
