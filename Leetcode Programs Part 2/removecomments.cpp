class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string temp;
        for (auto & str : source) {
            temp += str;
            temp.push_back('\n');
        }
        vector<string> result;
        size_t pos = 0;
        int n = temp.size();
        string current_line;
        while(pos < n) {
            if(temp.substr(pos, 2) == "//") {
                if (current_line.size() > 0) {
                    result.push_back(current_line);
                    current_line.clear();
                }
                pos = temp.find("\n", pos);
                pos += 1;
            } 
            else if (temp.substr(pos, 2) == "/*") {
                pos = temp.find("*/", pos + 2);
                pos += 2;
            } 
            else if (temp.substr(pos, 1) == "\n"){
                if (current_line.size() > 0) {
                    result.push_back(current_line);
                    current_line.clear();
                }
                pos += 1;
            } 
            else {
                current_line.push_back(temp[pos]);
                pos += 1;
            }
        }
        return result;
    }
};
