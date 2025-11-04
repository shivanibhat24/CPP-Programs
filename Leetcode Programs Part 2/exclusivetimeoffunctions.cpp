class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        vector<pair<int, int>> st;
        for (int j = 0, m = logs.size(); j < m; ++j) {
            string& log = logs[j];
            int id = 0, time = 0;
            bool isStart = false;
            int i = 0, len = log.size();
            while (log[i] != ':') id = id * 10 + (log[i++] - '0');
            ++i;
            if (log[i] == 's') {
                isStart = true;
                i += 6;
            } 
            else i += 4;
            while (i < len) time = time * 10 + (log[i++] - '0');
            if (isStart) st.push_back({id, time});
            else {
                auto [fid, start] = st.back(); st.pop_back();
                int duration = time - start + 1;
                res[fid] += duration;
                if (!st.empty()) res[st.back().first] -= duration;
            }
        }
        return res;
    }
};
