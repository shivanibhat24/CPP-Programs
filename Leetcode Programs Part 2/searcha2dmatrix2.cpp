class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int xx = 0;
        int yy = n-1;
        while(xx<m && yy>=0){
            if(matrix[xx][yy]==target) return true;
            else if(matrix[xx][yy]>target) yy--;
            else xx++;
        }
        return false;
    }
};
