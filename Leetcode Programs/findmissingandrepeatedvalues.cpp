class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> visited(n * n + 1, false);
        int repeatedValue = -1;
        int xorWithoutAB = 0; 
        int xorOfAll = 0;
        int cnt = 1;
        for (auto& row : grid) {
            for (int element : row) {
                xorWithoutAB ^= element;
                xorOfAll ^= cnt;
                cnt += 1;
                if (repeatedValue == -1) {
                    if (visited[element]) {
                        repeatedValue = element;
                    } else {
                        visited[element] = true;
                    }
                }
            }
        }
        int missingValue = xorWithoutAB ^ xorOfAll ^ repeatedValue;
        return {repeatedValue, missingValue};
    }
};
