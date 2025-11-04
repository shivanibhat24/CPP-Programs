class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int len = pattern.length(), n = queries.size();
        vector<bool> res(n , true);
        for(int k = 0; k < n; ++k){
            int i = 0;
            for(int j = 0, m = queries[k].length(); j < m; ++j){
                if(i < len && pattern[i] == queries[k][j]) ++i;
                else if(queries[k][j] < 'a'){
                    res[k] = false;
                    break;
                }
            }
            if(i < len) res[k] = false;
        }
        return res;
    }
};
