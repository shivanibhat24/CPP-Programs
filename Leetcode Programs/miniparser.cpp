class Solution {
public:
    NestedInteger deserialize(std::string s) {
        int index = 0;
        return parseHelper(s, index);
    }
private:
    NestedInteger parseHelper(const std::string& s, int& index) {
        if (s[index] == '[') {
            index++; 
            NestedInteger current_list; 
            while (s[index] != ']') {
                current_list.add(parseHelper(s, index));
                if (s[index] == ',') {
                    index++;
                }
            }
            index++;
            return current_list;
        }
        else {
            int sign = 1;
            if (s[index] == '-') {
                sign = -1;
                index++; 
            }
            long long num = 0; 
            while (index < s.length() && s[index] >= '0' && s[index] <= '9') {
                num = num * 10 + (s[index] - '0');
                index++; 
            }
            return NestedInteger(static_cast<int>(num * sign));
        }
    }
};
