class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; ++i) {
            m[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int ind = q.front(); q.pop();
                if (ind == n - 1) return steps;
                if (ind + 1 < n && !visited[ind + 1]) {
                    visited[ind + 1] = true;
                    q.push(ind + 1);
                }
                if (ind - 1 >= 0 && !visited[ind - 1]) {
                    visited[ind - 1] = true;
                    q.push(ind - 1);
                }
                for (int nei : m[arr[ind]]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
                m[arr[ind]].clear();
            }
            steps++;
        }
        return -1;
    }
};
