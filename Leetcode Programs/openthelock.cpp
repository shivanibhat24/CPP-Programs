class Solution {
public:
    int openLock(vector<string>& deadends, const string& target) {
        bool seen[10000] = {0};
        for (const string& s : deadends) {
            seen[stoi(s)] = 1;
        }
        if (seen[0]) return -1;
        int tgt = stoi(target);
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        seen[0] = 1;
        while (!q.empty()) {
            auto [turn, code] = q.front(); q.pop();
            if (code == tgt) return turn;
            for (int d = 0; d < 4; ++d) {
                int pow10 = pow10s[d];
                int digit = (code / pow10) % 10;
                for (int diff : {-1, 1}) {
                    int new_digit = (digit + diff + 10) % 10;
                    int new_code = code + (new_digit - digit) * pow10;
                    if (!seen[new_code]) {
                        seen[new_code] = 1;
                        q.emplace(turn + 1, new_code);
                    }
                }
            }
        }
        return -1;
    }
private:
    static constexpr int pow10s[4] = {1, 10, 100, 1000};
};
