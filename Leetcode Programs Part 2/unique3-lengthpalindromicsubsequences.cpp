class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(),count=0;
        vector<pair<int,int>> st(26,{-1,-1});

        for(int i=0;i<n;i++){
            if(st[s[i]-'a'].first==-1){
                st[s[i]-'a'].first = i;
            }
            st[s[i]-'a'].second = i;
        }

        for(int i=0;i<26;i++){
            int low = st[i].first;
            if(low==-1) continue;

            int high = st[i].second;

            unordered_set<char> temp;
            for(int j=low+1;j<high;j++){
                temp.insert(s[j]);
            }
            count += temp.size();
        }
        return count;
    }
};
