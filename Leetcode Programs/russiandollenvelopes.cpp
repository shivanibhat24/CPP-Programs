class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int, int>> Lis;
        for (int i = 0; i < n; ++i) {
            Lis.push_back({envelopes[i][0], envelopes[i][1]});
        }
        sort(Lis.begin(), Lis.end(),[&](auto L1, auto L2){return L1.first < L2.first || (L1.first == L2.first && L1.second > L2.second);});
        vector<int> m;
        m.push_back(Lis[0].second);        
        for (int y = 1; y < n; y++) {
            if (m.back() < Lis[y].second) m.push_back(Lis[y].second);
            else {
                m[lower_bound(m.begin(), m.end(), Lis[y].second)-m.begin()] = Lis[y].second;
            }
        }
        return m.size();
    }
};
