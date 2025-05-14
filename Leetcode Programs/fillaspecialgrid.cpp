class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        int size = 1<<n; 
        vector<vector<int>>grid(size,vector<int>(size,0));
        grid[0][0]=0;
        int currN = 0;
        while (currN < n) {
            int currSize = 1 << currN; 
            int square = currSize * currSize;           
            for (int i = 0; i < currSize; ++i) {
                for (int j = 0; j < currSize; ++j) {
                    int val = grid[i][j];
                    
                    grid[i][j] = val + 3 * square;                         
                    grid[i][j + currSize] = val;                          
                    grid[i + currSize][j + currSize] = val + square;      
                    grid[i + currSize][j] = val + 2 * square;             
                }
            }
            currN++;
        }
        return grid;        
    }
};
