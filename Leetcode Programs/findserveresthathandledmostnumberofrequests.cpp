class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> count(k, 0);
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        for (int i = 0; i < k; ++i) {
            free.push(i);
        }        
        for (int i = 0; i < arrival.size(); ++i) {
            int start = arrival[i];
            while (!busy.empty() && busy.top().first <= start) {
                auto [_, serverId] = busy.top();
                busy.pop();
                int modifiedId = ((serverId - i) % k + k) % k + i;
                free.push(modifiedId);
            }
            if (!free.empty()) {
                int busyId = free.top() % k;
                free.pop();
                busy.push(make_pair(start + load[i], busyId));
                count[busyId]++;
            }
        }
        vector<int> answer;
        auto maxJob = *max_element(count.begin(), count.end());
        for (int i = 0; i < k; ++i) {
            if (count[i] == maxJob) {
                answer.push_back(i);
            }
        }        
        return answer;
    }
};
