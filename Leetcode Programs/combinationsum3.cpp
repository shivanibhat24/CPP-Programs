class Solution {
public:
    void getCombinationSum(int n, int k, int index, int count, int sum, vector<int>& arr, vector<vector<int>> &ans) {
        if (count == k) {
            if (sum == n) {
                ans.push_back(arr);
            }
            return;
        }
        for(int i=index; i<=9; i++) {
            arr.push_back(i);
            sum += i;
            getCombinationSum(n, k, i+1, count+1, sum, arr, ans);
            arr.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {        
       vector<vector<int>> ans;
       vector<int> arr;
       int count = 0;
       int sum = 0;
       int index = 1;
       getCombinationSum(n, k, index, count, sum, arr, ans);
       return ans;
    }
};
