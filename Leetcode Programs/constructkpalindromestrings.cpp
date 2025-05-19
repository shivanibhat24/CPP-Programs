class Solution {
public:
    bool canConstruct(string s, int k) {
     if(s.length()<k) return false;
     if(s.length()==k) return true;
     vector<int>fre(26);
     int odd=0;
     for(auto it:s)
     {
        fre[it-'a']++;
     }   
     for(int i=0;i<26;i++)
     {
        if(fre[i]%2==1)
        {
            odd++;
        }
     }
     return odd<=k;
    }
};
