class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int m = req_skills.size();
        int n = people.size();
        unordered_map<string,int> skill_index;
        for (int i = 0; i < m; i++) {
            skill_index[req_skills[i]] = i;
        }
        vector<int> peopleMask(n, 0);
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (const string &skill : people[i]) {
                mask |= 1 << skill_index[skill];
            }
            peopleMask[i] = mask;
        }        
        int FULL = (1 << m) - 1;
        const int INF = n + 1;
        vector<int> dp(1 << m, INF);
        vector<int> prev(1 << m, -1), pick(1 << m, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int pm = peopleMask[i];
            if (pm == 0) continue;
            for (int mask = FULL; mask >= 0; mask--) {
                if (dp[mask] == INF) continue;
                int newMask = mask | pm;
                if (dp[mask] + 1 < dp[newMask]) {
                    dp[newMask] = dp[mask] + 1;
                    prev[newMask] = mask;
                    pick[newMask] = i;
                }
            }
        }
        vector<int> team;
        int cur = FULL;
        while (cur) {
            team.push_back(pick[cur]);
            cur = prev[cur];
        }
        reverse(team.begin(), team.end());
        return team;
    }
};
int ddddddd(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<string> req_skills(m);
    for (int i = 0; i < m; i++){
        cin >> req_skills[i];
    }
    int n;
    cin >> n;
    vector<vector<string>> people(n);
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        people[i].resize(k);
        for (int j = 0; j < k; j++){
            cin >> people[i][j];
        }
    }
    Solution sol;
    vector<int> ans = sol.smallestSufficientTeam(req_skills, people);
    for (int idx : ans) {
        cout << idx << " ";
    }
    cout << "\n";
    return 0;
}
