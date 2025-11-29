class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();

        vector<bool> seen(n);

        unordered_map<string, int> freq;

        queue<pair<int, int>> q;
        q.emplace(0, id);
        seen[id] = true;

        while (!q.empty()) {
            auto [d, j] = q.front(); q.pop();
            if (d == level) {
                for (string& w : watchedVideos[j]) {
                    ++freq[w];
                }
                continue;
            }

            for (int next : friends[j]) {
                if (!seen[next]) {
                    seen[next] = true;
                    q.emplace(d + 1, next);
                }
            }
        }

        vector<pair<int, string>> watched;
        for (auto& [s, f] : freq) {
            watched.emplace_back(f, move(s));
        }

        sort(watched.begin(), watched.end());
        vector<string> res;
        for (auto& [f, s] : watched) {
            res.emplace_back(move(s));
        }

        return res;
    }
};
