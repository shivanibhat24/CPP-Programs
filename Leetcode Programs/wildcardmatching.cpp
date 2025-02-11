class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int starIdx = -1, pmatched = -1;
        int si = 0, pi = 0;
        while(si<sLen){
            if(pi<pLen && (p[pi]==s[si] || p[pi]=='?')){
                pi++;
                si++;
            }else if(pi<pLen && p[pi]=='*'){
                starIdx=pi;
                pmatched = si;
                pi++;
            }else if(starIdx!=-1){
                pi = starIdx+1;
                pmatched++;
                si=pmatched;
            }else{
                return false;
            }
        }
        while(pi<pLen && p[pi]=='*'){
            pi++;
        }
        return pi==pLen;
    }
};
