class Solution {
public:
    char findTheDifference(string s, string t) {
    unordered_map<char,int>mpp;
    for(auto ch:s) mpp[ch]++;
    for(auto ch:t) mpp[ch]--;
    for(auto it:mpp){
        if(it.second<0) return it.first;
    }
    return ' ';
    }
};
