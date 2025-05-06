class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ret = INT_MIN;
        priority_queue<pair<int, int>> maxHeap;
        for(const auto& point : points){
            int x_j = point[0], y_j = point[1];
            while(!maxHeap.empty() && x_j - maxHeap.top().second > k){
                maxHeap.pop();
            }
            if(!maxHeap.empty()){
                ret = max(ret, x_j + y_j + maxHeap.top().first);
            }
            maxHeap.push({-x_j + y_j, x_j});
        }
        return ret;
    }
};
