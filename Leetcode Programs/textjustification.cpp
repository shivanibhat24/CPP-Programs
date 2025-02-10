class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int index = 0;
        while (index < n) {
            int totalChars = words[index].size();
            int last = index + 1;

            while (last < n && totalChars + words[last].size() + (last - index) <= maxWidth) {
                totalChars += words[last].size();
                last++;
            }
            string line;
            int gaps = last - index - 1;
            if (last == n || gaps == 0) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int spaces = (maxWidth - totalChars) / gaps;
                int extraSpaces = (maxWidth - totalChars) % gaps;

                for (int i = index; i < last - 1; i++) {
                    line += words[i];
                    line += string(spaces + (i - index < extraSpaces ? 1 : 0), ' ');
                }
                line += words[last - 1];
            }

            result.push_back(line);
            index = last;
        }
        return result;
    }
};
