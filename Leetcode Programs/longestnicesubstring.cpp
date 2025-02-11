class Solution {
    int left=-1, right=-1;
    void helper(int l, int r, string& s){
        if(l>=r) return;
        vector<bool> small(26, 0), large(26, 0);
        for(int i=l;i<=r;i++){
            if(s[i]>='a' && s[i]<='z') small[s[i]-'a']=true;
            else large[s[i]-'A']=true;
        }
        for(int i=l;i<=r;i++){
            int a=-1;
            if(s[i]>='a' && s[i]<='z') a=s[i]-'a';
            else a=s[i]-'A';
            if(small[a] && large[a]) continue;
            else if(small[a] || large[a]){
                helper(l, i-1, s);
                helper(i+1, r, s);
                return;
            }
        }
        if(left==-1 || right-left+1 < r-l+1){
            left=l;
            right=r;
        }
        else if(right-left+1 == r-l+1 && left > l){
            left=l;
            right=r;
        }
    }
public:
    string longestNiceSubstring(string s) {
        int n=s.length();
        helper(0, n-1, s);
        return left == -1 ? "":  s.substr(left, right-left+1);
    }
};
