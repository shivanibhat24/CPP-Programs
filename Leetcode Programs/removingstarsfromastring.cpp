class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        vector<char> a;
        for(int i = 0; i < n; i++){
            if(s[i]=='*'){         
                a.pop_back();
            }else{
                a.push_back(s[i]);
            }
        }
        string ans(a.begin(), a.end());
        return ans;
    }
};
