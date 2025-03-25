bool canCutDimension(const vector<vector<int>> &rectangles, int dim) {
    vector<pair<int,int>> intervals;
    intervals.reserve(rectangles.size());
    for (auto &r : rectangles) {
        if(dim == 0)
            intervals.push_back({r[0], r[2]});
        else
            intervals.push_back({r[1], r[3]});
    }
    sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first < b.first;
    });    
    int blocks = 0;
    int curStart = 0, curEnd = 0;
    bool first = true;
    for(auto &in : intervals) {
        int s = in.first, e = in.second;
        if(first){
            curStart = s;
            curEnd = e;
            first = false;
            blocks++; 
        } else {
            if(s < curEnd) {
                curEnd = max(curEnd, e);
            } else {
                blocks++;
                curStart = s;
                curEnd = e;
            }
        }
    }
    return blocks >= 3;
} 
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        if(canCutDimension(rectangles, 1)) return true;
        if(canCutDimension(rectangles, 0)) return true;
        return false;
    }
};
