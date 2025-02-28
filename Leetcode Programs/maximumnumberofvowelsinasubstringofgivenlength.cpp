class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0; 
        int numVowels = 0;
        int maxVowels = 0;
        for(int right = 0; right < s.size(); right++) {            
            numVowels += isVowel(s[right]);
            if (right - left + 1 < k) {
                continue;
            }
            maxVowels = max(numVowels, maxVowels);
            numVowels -= isVowel(s[left++]);
        }
        return maxVowels;         
    }
    private: 
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
