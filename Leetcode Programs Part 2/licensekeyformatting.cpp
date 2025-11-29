class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
         std::string cleanString;
        for (char c : s) {
            if (c != '-') {
                cleanString += toupper(c);
            }
        }

        // Get the length of the string without dashes
        int length = cleanString.size();
        
        // Calculate the size of the first group
        int firstGroup = length % k;
        if (firstGroup == 0 && length > k) {
            firstGroup = k;
        }
        
        std::string result;

        // Append the first group
        result += cleanString.substr(0, firstGroup);

        // Append the remaining groups
        for (int i = firstGroup; i < length; i += k) {
            if (!result.empty()) {
                result += '-';
            }
            result += cleanString.substr(i, k);
        }

        return result;
    }
};
