class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int n = s.size();
        int numCount = (n + 1) / 2;
        vector<int> nums;
        vector<char> ops;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums.push_back(s[i] - '0');
            } else {
                ops.push_back(s[i]);
            }
        }
        vector<int> tempNums;
        vector<char> tempOps;
        tempNums.push_back(nums[0]);        
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == '*') {
                int last = tempNums.back();
                tempNums.pop_back();
                tempNums.push_back(last * nums[i + 1]);
            } else {
                tempNums.push_back(nums[i + 1]);
                tempOps.push_back(ops[i]);
            }
        }
        int correct = tempNums[0];
        for (int i = 0; i < tempOps.size(); i++) {
            correct += tempNums[i + 1];
        }
        vector<vector<unordered_set<int>>> dp(numCount, vector<unordered_set<int>>(numCount));
        for (int i = 0; i < numCount; i++) {
            dp[i][i].insert(nums[i]);
        }
        for (int len = 2; len <= numCount; len++) {
            for (int i = 0; i <= numCount - len; i++) {
                int j = i + len - 1;
                for (int k = i; k < j; k++) {
                    char op = ops[k];
                    for (int left : dp[i][k]) {
                        for (int right : dp[k + 1][j]) {
                            int val;
                            if (op == '+') {
                                val = left + right;
                            } else {
                                val = left * right;
                            }
                            if (val <= 1000) {
                                dp[i][j].insert(val);
                            }
                        }
                    }
                }
            }
        }
        unordered_set<int> possible = dp[0][numCount - 1];
        int score = 0;
        for (int ans : answers) {
            if (ans == correct) {
                score += 5;
            } else if (possible.count(ans)) {
                score += 2;
            }
        }
        return score;
    }
};
