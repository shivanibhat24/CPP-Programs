class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) {
            A[i] = points[i][0] + points[i][1];
            B[i] = points[i][0] - points[i][1];
        }
        vector<pair<int, int>> maxA = {{INT_MIN, -1}, {INT_MIN, -1}};
        vector<pair<int, int>> minA = {{INT_MAX, -1}, {INT_MAX, -1}};
        vector<pair<int, int>> maxB = {{INT_MIN, -1}, {INT_MIN, -1}};
        vector<pair<int, int>> minB = {{INT_MAX, -1}, {INT_MAX, -1}};
        for (int i = 0; i < n; i++) {
            if (A[i] > maxA[0].first) {
                maxA[1] = maxA[0];
                maxA[0] = {A[i], i};
            } else if (A[i] > maxA[1].first) {
                maxA[1] = {A[i], i};
            }
            if (A[i] < minA[0].first) {
                minA[1] = minA[0];
                minA[0] = {A[i], i};
            } else if (A[i] < minA[1].first) {
                minA[1] = {A[i], i};
            }
            if (B[i] > maxB[0].first) {
                maxB[1] = maxB[0];
                maxB[0] = {B[i], i};
            } else if (B[i] > maxB[1].first) {
                maxB[1] = {B[i], i};
            }
            if (B[i] < minB[0].first) {
                minB[1] = minB[0];
                minB[0] = {B[i], i};
            } else if (B[i] < minB[1].first) {
                minB[1] = {B[i], i};
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int maxAVal = (i == maxA[0].second) ? maxA[1].first : maxA[0].first;
            int minAVal = (i == minA[0].second) ? minA[1].first : minA[0].first;
            int maxBVal = (i == maxB[0].second) ? maxB[1].first : maxB[0].first;
            int minBVal = (i == minB[0].second) ? minB[1].first : minB[0].first;
            int dist = max(maxAVal - minAVal, maxBVal - minBVal);
            res = min(res, dist);
        }
        return res;
    }
};
