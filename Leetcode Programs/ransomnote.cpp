class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag_map;
        for (auto ch : magazine) {
            mag_map[ch]++;
        }
        for (auto ch : ransomNote) {
            if (mag_map[ch]-- == 0) {
                return false;
            }
        }
        return true;
    }
};
