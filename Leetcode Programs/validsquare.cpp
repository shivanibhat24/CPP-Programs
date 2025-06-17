class Solution {
public:
    int getDistance(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<int> distances;        
        for(int i = 0; i < 4; i++) {
            for(int j = i + 1; j < 4; j++) {
                int dist = getDistance(points[i], points[j]);
                if(dist == 0) return false; 
                distances.insert(dist);
            }
        }
        return distances.size() == 2;
    }
};
