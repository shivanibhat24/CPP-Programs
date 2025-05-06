class Solution {
private:
    class Trie {
    private:
        struct Node {
            stack<long long> vals; 
            unordered_map<char,Node*> links; 
            Node() {}
            ~Node() { for (pair<char, Node*> link : this->links) delete link.second; }
        };
        Node *root;
        Node* get_from_string(const string& key) {
            Node *curr = this->root;
            for (char c : key) {
                if (!curr->links.contains(c)) curr->links[c] = new Node();
                curr = curr->links[c];
            }
            return curr;
        }
    public:
        Trie() : root(new Node()) {}
        ~Trie() { delete this->root; }
        void push(const string& variable, long long value) {
            this->get_from_string(variable)->vals.push(value);
        }
        void pop(const string& variable) {
            this->get_from_string(variable)->vals.pop();
        }
        long long get(const string& variable) {
            return this->get_from_string(variable)->vals.top();
        }
    };    
public:
    int evaluate(string expression) const {
        const int n = expression.length();
        stack<int> parens;
        vector<int> paren_match(n, -1);
        int i = 0;
        while (i < n) {
            if (expression[i] == '(') parens.push(i);
            else if (expression[i] == ')') {
                paren_match[parens.top()] = i;
                parens.pop();
            } else if (expression[i] == '-' || isdigit(expression[i]) || isalpha(expression[i])) {
                int start = i;
                while (i < n - 1 && (isdigit(expression[i + 1]) || isalpha(expression[i + 1]))) i++;
                paren_match[start] = i;
            }
            i++;
        }
        Trie vars;
        function<long long(int,int)> eval;
        eval = [&eval, &paren_match, n, &expression, &vars] (int l, int r) -> long long {
            if (expression[l] == '-' || isdigit(expression[l])) return stoll(expression.substr(l, r - l + 1));
            else if (isalpha(expression[l])) return vars.get(expression.substr(l, r - l + 1));
            else if (expression[l + 1] != 'l') {
                bool adding = expression[l + 1] == 'a';
                int l1, r1, l2, r2; 
                l1 = l + (adding ? 5 : 6);
                r1 = paren_match[l1];
                l2 = r1 + 2;
                r2 = paren_match[l2];
                return adding ? eval(l1, r1) + eval(l2, r2) : eval(l1, r1) * eval(l2, r2);
            }
            int i = l + 5;
            while (paren_match[i] != r - 1) {
                int l1, r1, l2, r2;
                l1 = i;
                r1 = paren_match[l1];
                l2 = r1 + 2;
                r2 = paren_match[l2];
                vars.push(expression.substr(l1, r1 - l1 + 1), eval(l2, r2));
                i = r2 + 2;
            }
            long long result = eval(i, paren_match[i]);
            i = l + 5;
            while (paren_match[i] != r - 1) {
                vars.pop(expression.substr(i, paren_match[i] - i + 1));
                i = paren_match[paren_match[i] + 2] + 2;
            }
            return result;
        };
        return eval(0, n - 1);
    }
};
