class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for (char c : s) {
            if (isalnum(c)) {
                s2.push_back(tolower(c));
            }
        }
        int left = 0, right = s2.size() - 1;
        while (left < right) {
            if (s2[left] != s2[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
