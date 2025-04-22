class Solution {
public:
    int countSubsetSum(vector<int>& arr, int n, int sum) {
        vector<vector<int>> t(n + 1, vector<int>(sum + 1));

        for (int i = 0; i <= n; i++)
            t[i][0] = 1;
        for (int j = 1; j <= sum; j++)
            t[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& arr, int d) {
        int sum = 0;
        int n = arr.size();
        for (int x : arr) {
            sum += x;
        }

        if (abs(d) > sum || (sum + d) % 2 != 0)
            return 0;

        return countSubsetSum(arr, n, (sum + d) / 2);
    }
};
