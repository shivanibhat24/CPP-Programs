class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256]={0};
        bool ischarmapped[256]={0};
        for(int i =0;i<s.size();i++){
            if(hash[s[i]]==0 && ischarmapped[t[i]]==0){
                hash[s[i]]=t[i];
                ischarmapped[t[i]]=true;
            }
        }
        for(int i =0;i<s.length();i++){
            if((hash[s[i]])!=t[i] ){
                return false;
            }
            
        }
        return true;        
    }
};
