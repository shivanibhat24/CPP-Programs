class Solution {
public:
    int dist(int size, int p, int t){
        return min(abs(t - p), size - abs(t - p));
    }
    int findRotateSteps(string ring, string key){
        int mp[26][100] = {{0}};
        int freq[26] = {0};
        int dp[100][100] = {{0}};
        int n = ring.size(), m = key.size();
        for(int i = 0; i < n; ++i) {
            mp[ring[i] - 'a'][freq[ring[i] - 'a']++] = i;
        }
        for(int i = 0; i < freq[key[0]-'a']; ++i){
                dp[0][mp[key[0] - 'a'][i]] = dist(n, 0, mp[key[0]-'a'][i]) + 1;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < freq[key[i] - 'a']; ++j) {
                int mini = INT_MAX;
                for(int k = 0; k < freq[key[i - 1] - 'a']; ++k){
                    mini = min(mini, dp[i - 1][mp[key[i - 1] - 'a'][k]] + 
                    dist(n, mp[key[i] - 'a'][j], mp[key[i - 1] - 'a'][k]) + 1);
                }
                dp[i][mp[key[i] - 'a'][j]] = mini;
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < freq[key.back() - 'a']; ++i) {
            res = min(res, dp[m - 1][mp[key[m - 1] - 'a'][i]]);
        }
        return res;
    }
};
