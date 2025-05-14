class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        n++;
        vector<int> forwardRow(n, -1), backwardRow(n, -1), forwardCol(n, -1), backwardCol(n, -1);
        for(auto &i : buildings) {
            forwardRow[i[0]] = (forwardRow[i[0]] == -1) ? (i[1]) : (min(i[1], forwardRow[i[0]]));
            backwardRow[i[0]] = (backwardRow[i[0]] == -1) ? (i[1]) : (max(i[1], backwardRow[i[0]]));

            forwardCol[i[1]] = (forwardCol[i[1]] == -1) ? (i[0]) : (min(i[0], forwardCol[i[1]]));
            backwardCol[i[1]] = (backwardCol[i[1]] == -1) ? (i[0]) : (max(i[0], backwardCol[i[1]]));
        }
        int cnt = 0;
        for (auto &i : buildings) {
            if ( forwardRow[i[0]] != i[1] &&  backwardRow[i[0]] != i[1] && forwardCol[i[1]] != i[0] && backwardCol[i[1]] != i[0]) cnt++;
        }
        return cnt;
        
    }
};
