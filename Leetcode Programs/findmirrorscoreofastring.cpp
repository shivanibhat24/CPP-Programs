class Solution {
public:
    long long calculateScore(string s) {
        long long int ans = 0LL;
        vector<vector<int>>m(26);
        for(int i=0;i<s.length();i++){
            if(m[abs(s[i]-'a'-25)].empty()) m[s[i]-'a'].push_back(i);
            else{
                ans+=(long long int)(i-m[abs(s[i]-'a'-25)].back());
                m[abs(s[i]-'a'-25)].pop_back();
            }
        }
        return ans;
    }
};
