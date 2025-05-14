class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for(char c: s){
            freq[c - 'a']++;
        }
        int max_vowel = 0;
        int max_con = 0;
        for(int i =0;i<26;i++){
            if(i == 0 || (i == 'e' - 'a') || (i == 'i' - 'a')||(i == 'o' - 'a')||(i == 'u' - 'a' )) max_vowel = max(max_vowel, freq[i]);
            else max_con = max(max_con, freq[i]);
        }
        return max_vowel + max_con;
    }
};
