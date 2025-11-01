class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Build 2D prefix sum (row-wise)
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = matrix[i][j] + (j > 0 ? prefix[i][j-1] : 0);
            }
        }

        int count = 0;

        // Step 2: Fix top row r1 and bottom row r2
        for (int r1 = 0; r1 < n; r1++) {
            vector<int> rowSum(m, 0); // sum of elements between r1..r2 in each column
            for (int r2 = r1; r2 < n; r2++) {
                // Update rowSum for this row r2
                for (int c = 0; c < m; c++) {
                    rowSum[c] += matrix[r2][c]; // can also use prefix[r2][c] - prefix[r1-1][c] if r1>0
                }

                // Step 3: Use 1D prefix sum + hashmap over rowSum
                unordered_map<int,int> freq;
                freq[0] = 1;
                int curr = 0;
                for (int c = 0; c < m; c++) {
                    curr += rowSum[c];
                    count += freq[curr - target];
                    freq[curr]++;
                }
            }
        }

        return count;
    }
};
