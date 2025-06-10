class Solution {
public:
    string oddString(const vector<string>& words) {
        int matchingFirst = 0;
        int mismatchIndex = 0;
        for (size_t i = 1; i < words.size(); i++) {
            if (matchesDiff(words[0], words[i])) {
                matchingFirst++;
            } else {
                mismatchIndex = i;
            }
        }
        return matchingFirst > 0 ? words[mismatchIndex] : words[0];
    }
private:
    static bool matchesDiff(const std::string& a, const std::string& b) {
        for (size_t i = 0; i < a.length() - 1; i++) {
            if (a[i + 1] - a[i] != b[i + 1] - b[i]) {
                return false;
            }
        }
        return true;
    }
    
};
