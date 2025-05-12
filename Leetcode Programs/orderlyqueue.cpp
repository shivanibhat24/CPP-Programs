class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n=s.length();
        string t=s;
        if(k==1){
            while(n--){
                char c=s[0];
                s.erase(s.begin());
                s.push_back(c);
                if(s<t)t=s;
            }
            return t;
        }
        sort(t.begin(),t.end());
        return t;        
    }
};
