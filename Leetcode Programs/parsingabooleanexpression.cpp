class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st {};
        char cur_op {};
        for (char c: expression) {
            if (c == ',' || c == '(') continue;
            if (c != ')') st.push(c);
            else {
                bool t = false, f = false;
                while (st.top() != '!' && st.top() != '|' && st.top() != '&') {
                    char top = st.top(); st.pop();
                    if (top == 't') t = true;
                    if (top == 'f') f = true;
                }
                char top = st.top(); st.pop();
                if (top == '|') st.push(t ? 't' : 'f');
                else if (top == '&') st.push(f ? 'f' : 't');
                else st.push(f ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};
