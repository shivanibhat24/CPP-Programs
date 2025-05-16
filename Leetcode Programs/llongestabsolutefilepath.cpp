class Solution {
public:
    int lengthLongestPath(string input) {
        int longest = 0;
        std::unordered_map<int, int> pathMap;
        pathMap[0] = 0;
        std::istringstream ss(input);
        std::string line;
        while (getline(ss, line)) {
            auto namePos = line.find_last_of('\t') + 1;
            int depth = namePos;
            std::string name = line.substr(namePos);
            if (name.find('.') != std::string::npos) {
                longest = std::max(
                    longest, pathMap[depth] + static_cast<int>(name.length()));
            } else {
                pathMap[depth + 1] =
                    pathMap[depth] + static_cast<int>(name.length()) + 1;
            }
        }
        return longest;
    }
};
