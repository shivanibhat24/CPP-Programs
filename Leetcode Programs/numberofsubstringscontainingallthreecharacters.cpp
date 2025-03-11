class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0;
        int hash[3]={-1,-1,-1};
        int count=0;
        while(i<n)
        {
            hash[s[i]-'a']=i;
            if(hash[0]!=-1&&hash[1]!=-1&&hash[2]!=-1)
            {
                count+=(1+min(hash[0],min(hash[1],hash[2])));
            }
            i++;
        }
        return count;
    }
};
