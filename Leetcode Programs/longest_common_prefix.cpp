#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        
        // Sort the strings
        sort(strs.begin(), strs.end());
        
        // Get the first and last string after sorting
        string first = strs[0];
        string last = strs[strs.size() - 1];
        
        // Compare characters of first and last string
        for (int i = 0; i < min(first.length(), last.length()); i++) {
            if (first[i] != last[i]) {
                return ans; // No common prefix found
            }
            ans += first[i]; // Add the common character to the result
        }
        
        return ans;
    }
};
