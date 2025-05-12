class MyCalendarThree {
private: 
    map<int, int> bookingCount;
    int maxCount;
public:
    MyCalendarThree() {
        maxCount = 0;
    }
    int book(int startTime, int endTime) {
        bookingCount[startTime]++;
        bookingCount[endTime]--;
        int onGoing = 0;
        for(auto [key, val] : bookingCount) {
            onGoing += val;
            maxCount = max(maxCount, onGoing);
            if(key > endTime) break;
        }        
        return maxCount;
    }
};
