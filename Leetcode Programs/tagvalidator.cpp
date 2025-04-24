#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        stack<string> tagStack;
        int i = 0;
        int n = code.size();

        if (n == 0 || code[0] != '<') return false;

        while (i < n) {
            if (i + 9 < n && code.substr(i, 9) == "<![CDATA[") {
                // CDATA section
                if (tagStack.empty()) return false; // CDATA must be inside a tag
                int j = code.find("]]>", i);
                if (j == string::npos) return false;
                i = j + 3;
            } else if (i + 1 < n && code[i] == '<') {
                bool isEnd = (code[i + 1] == '/');
                int j = code.find('>', i);
                if (j == string::npos) return false;
                string tag = code.substr(i + (isEnd ? 2 : 1), j - i - (isEnd ? 2 : 1));

                // Tag validation
                if (tag.empty() || tag.size() > 9) return false;
                for (char c : tag) {
                    if (c < 'A' || c > 'Z') return false;
                }

                if (isEnd) {
                    if (tagStack.empty() || tagStack.top() != tag) return false;
                    tagStack.pop();
                    if (tagStack.empty() && j + 1 != n) return false;
                } else {
                    tagStack.push(tag);
                }

                i = j + 1;
            } else {
                if (tagStack.empty()) return false;
                i++;
            }
        }

        return tagStack.empty();
    }
};
