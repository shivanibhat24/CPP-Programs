class Solution {
    void Backtrack(int offset, string & path, long long left_op, auto const& num, long long target, auto & answer) {
        if (offset == num.size()) {
            if (left_op == target) {
                answer.push_back(path);
            }
            return;
        }
        long long value = 0;
        int placeholder = path.size();        
        if (offset != 0) {
            path.push_back('x');
        }
        for (int i = offset; i < num.size(); ) {
            if (num[offset] == '0' && offset < i) {
                break; 
            }
            auto curr = num[i++];
            value = value * 10 + (curr - '0');
            if (offset != 0) {
                path.push_back(curr);
                path[placeholder] = '+';
                Backtrack(i, path, value, num, target - left_op, answer);

                path[placeholder] = '-';
                Backtrack(i, path, -value, num, target - left_op, answer);

                path[placeholder] = '*';
                Backtrack(i, path, left_op * value, num, target, answer);
            } else {
                path.push_back(curr);
                Backtrack(i, path, value, num, target, answer);
            }

        }
        path.erase(placeholder);      
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> answer;
        string path;
        Backtrack(0, path, 0, num, target, answer);
        return answer;
    }
};
