class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        int scoreFirst = predictTheWinnerFrom(nums, 0, n - 1, memo);
        int scoreTotal = accumulate(nums.begin(), nums.end(), 0);
        return scoreFirst >= scoreTotal - scoreFirst;
    }    
private:
    int predictTheWinnerFrom(vector<int>& nums, int i, int j, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (i == j) return nums[i];
        if (memo[i][j] != -1) return memo[i][j];        
        int curScore = max(
            nums[i] + min(predictTheWinnerFrom(nums, i + 2, j, memo), 
                          predictTheWinnerFrom(nums, i + 1, j - 1, memo)),
            nums[j] + min(predictTheWinnerFrom(nums, i, j - 2, memo), 
                          predictTheWinnerFrom(nums, i + 1, j - 1, memo))
        );        
        return memo[i][j] = curScore;
    }
};
