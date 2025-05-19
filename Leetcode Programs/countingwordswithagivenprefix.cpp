class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int p=pref.length();
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            if(words[i].length()>=p&& words[i].substr(0,p)==pref)
            {
                count++;
            }
        }
        return count;        
    }
};
