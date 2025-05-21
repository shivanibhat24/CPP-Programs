class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> tvector(n + 1, 0); 
        for (auto& t : trust) {
            tvector[t[0]]--; 
            tvector[t[1]]++; 
        }
        for (int i = 1; i <= n; i++) {
            if (tvector[i] == n - 1)
                return i;
        }
        return -1;
    }
};
