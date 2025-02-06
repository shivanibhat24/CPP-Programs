class Solution {
public:
    string reverseVowels(string s) {
        string temp ="";
        for(int i = s.size()-1 ; i>-1;i--){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
                s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
                s[i] == 'U') {
                    temp.push_back(s[i]);
            } 
        }
        int j = 0;
        for(int i = 0 ; i<s.size();i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
                s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
                s[i] == 'U') {
                    s[i] = temp[j++];
            } 
        }
        return s;
    }
};
