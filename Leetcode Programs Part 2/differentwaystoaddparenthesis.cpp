class Solution {
    unordered_map<string, vector<int>> memo;

    bool isOp(char c) {
        return c == '+' || c == '-' || c == '*';
    }

    vector<int> solve(const string &expr) {
        if (memo.count(expr)) return memo[expr];

        vector<int> res;
        bool hasOp = false;

        // check if this substring is just a number
        for (char c : expr) {
            if (isOp(c)) {
                hasOp = true;
                break;
            }
        }
        if (!hasOp) {
            res.push_back(stoi(expr));
            return memo[expr] = res;
        }

        int n = expr.size();
        for (int i = 0; i < n; ++i) {
            char c = expr[i];
            if (!isOp(c)) continue;

            string left = expr.substr(0, i);
            string right = expr.substr(i + 1);

            vector<int> L = solve(left);
            vector<int> R = solve(right);

            for (int a : L) {
                for (int b : R) {
                    if (c == '+') res.push_back(a + b);
                    else if (c == '-') res.push_back(a - b);
                    else res.push_back(a * b);
                }
            }
        }
        return memo[expr] = res;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        memo.clear();
        return solve(expression);
    }
};
