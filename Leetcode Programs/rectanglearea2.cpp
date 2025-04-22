class Solution {
    vector<vector<int>> intervals;
    int totalArea = 0;
    int mod = 1e9 + 7;
    vector<vector<int>> getMergedIntervals() {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        if(intervals.size() == 0) return merged;
        vector<int> prevInterval = intervals[0];
        for(int i = 1; i < intervals.size(); ++i) {
            if(prevInterval[1] < intervals[i][0]) {
                merged.push_back(prevInterval);
                prevInterval = intervals[i];
            } else {
                prevInterval[1] = max(prevInterval[1], intervals[i][1]);
            }
        }
        merged.push_back(prevInterval);
        return merged;
    }
    long long getArea(int width) {
        vector<vector<int>> merged = getMergedIntervals();
        long long currArea = 0;
        for(int i = 0; i < merged.size(); ++i) {
            currArea = (currArea + merged[i][1] - merged[i][0])%mod;
        }
        return (currArea*width)%mod;
    }
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<vector<int>> events;
        for(auto &rectangle: rectangles) {
            events.push_back({rectangle[0], 0, rectangle[1], rectangle[3]});
            events.push_back({rectangle[2], 1, rectangle[1], rectangle[3]});
        }
        sort(events.begin(), events.end());
        int prevX = events[0][0];
        for(int i = 0; i < events.size(); ++i) {
            int currX = events[i][0];
            int currWidth = currX - prevX;
            if(currWidth != 0) totalArea = (totalArea + getArea(currWidth))%mod;
            bool isClosing = events[i][1];
            if(isClosing) {
                auto it = find(intervals.begin(), intervals.end(), vector<int>{events[i][2], events[i][3]});
                intervals.erase(it);
            } else {
                intervals.push_back({events[i][2], events[i][3]});
            }
            prevX = currX;
        }
        return totalArea;
    }
};
