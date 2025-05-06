class Solution {
public:
    int solve(vector<int>& slices, int n, int e, int k ,vector<vector<int>>& memo){
        if(k == 0 || n > e) return 0;
        if(memo[n][k] != -1) return memo[n][k];
        int inc = slices[n] + solve(slices, n+2,e , k-1, memo);
        int exc = solve(slices, n+1,e,k, memo);
        return  memo[n][k] = max(inc, exc);
    }
    int solveTab(vector<int>& slices) {
        int k = slices.size();
        vector<int> prev(k + 2);
        vector<int> curr(k + 2);
        vector<int> next(k + 2);
        for(int index = k-2; index>=0; index--) {
            for(int n = 1; n <= k/3; n++) {
            int inc = slices[index] + next[n-1];
            int exc = curr[n];
            prev[n] = max(inc, exc);
            }
            next = curr;
            curr = prev;
        } 
        int case1 = curr[k/3];
        vector<int> prev1(k + 2);
        vector<int> curr1(k + 2);
        vector<int> next1(k + 2);
        for(int index = k-1; index>=1; index--) {
            for(int n = 1; n <= k/3; n++) {
            int inc = slices[index] + next1[n-1];
            int exc = curr1[n];
            prev1[n] = max(inc, exc);
            }
             next1 = curr1;
            curr1 = prev1;
        } 
        int case2 = curr1[k/3];
        return max(case1, case2);
    }
    int maxSizeSlices(vector<int>& slices) {
       return solveTab(slices);
    }
};
