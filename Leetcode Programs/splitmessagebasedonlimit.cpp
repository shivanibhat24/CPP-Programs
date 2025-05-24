class Solution {
public:
    int calcLines(int ml, int limit) {
        int d = 1;
        int prefix = 0;
        int first = 1;
        while(limit > 3 + d + d) {
            int lines = ceil((ml + prefix - d * first + d + 0.0) / (limit - 3 - d - d + 0.0));
            if (floor(log10(lines)) + 1 == d) return lines;
            prefix += (pow(10, d) - first)*d;
            first = pow(10, d);
            d++;
        }
        return 0;
    }
    vector<string> splitMessage(string message, int limit) {
        int lines = calcLines(message.length(), limit);        vector<string> ret;
        string total = "/" + to_string(lines) +">";
        for (int i = 0, pos=0; i < lines; i++) {
            int lid=i+1;
            string suffix = "<" + to_string(lid) + total;
            int len = limit - suffix.length();
            if (len + pos >= message.length())
                len = message.length() - pos;
            ret.push_back(message.substr(pos, len) + suffix);
            pos = pos + len;
        }
        return ret;    
    }
};
