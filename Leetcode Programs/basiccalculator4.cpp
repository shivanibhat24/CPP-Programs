class Solution {
public:
    void add(vector<pair<int,vector<string>>>& lhs, vector<pair<int,vector<string>>>& rhs) {
        for (auto& prr : rhs) {
            // ignore zeros
            if (prr.first == 0) continue;
            bool match = false;
            for (auto& prl : lhs) {
                if (prr.second == prl.second) {
                    prl.first += prr.first;
                    match = true;
                    break;
                }
            }
            if (!match) lhs.push_back(prr);
        }

        // remove zeros
        int sz = lhs.size();
        for (int i = 0; i < sz;) {
            if (lhs[i].first == 0) swap(lhs[i], lhs[--sz]);
            else i++;
        }
        lhs.resize(sz);
    }
    void mult(vector<pair<int,vector<string>>>& lhs, vector<pair<int,vector<string>>>& rhs) {
        vector<pair<int,vector<string>>> temp;
        
        // for (auto& k : lhs) cout << k.first << " " << k.second.size() << ", ";
        // cout << endl;
        // for (auto& k : rhs) cout << k.first << " " << k.second.size() << ", ";
        // cout << endl << endl;
        
        for (auto& prr : rhs) {
            // ignore zeros
            if (prr.first == 0) continue;
            for (auto& prl : lhs) {
                pair<int,vector<string>> term;
                term.first = prr.first * prl.first;
                term.second = prr.second;
                term.second.insert(term.second.end(), prl.second.begin(), prl.second.end());
                ranges::sort(term.second);
                vector<pair<int,vector<string>>> rhs = {term};
                add(temp, rhs);
            }
        }
        lhs = temp;
    }
    vector<pair<int,vector<string>>> conv(int coef, string var) {
        pair<int,vector<string>> res;
        res.first = coef;
        if (!var.empty()) res.second = {var};
        return {res};
    }
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string,int> subs;
        string& s = expression;
        int m = evalvars.size(), n = s.size();
        for (int i = 0; i < m; i++) subs[evalvars[i]] = evalints[i];

        stack<vector<pair<int,vector<string>>>> calc;
        stack<char> collapse;
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == ' ') continue;
            
            if (c == '(' || c == '*' || c == '+') { // expand
                collapse.push(c);
            }
            else if (c == '-') {
                collapse.push('+');
                collapse.push('*');
                calc.emplace(conv(-1, ""));
            }
            else { // flushable term
                vector<pair<int,vector<string>>> rhs;
                if (c >= 'a' && c <= 'z') { // variable
                    string var = "";
                    while (i < n && s[i] != ' ' && s[i] != ')') var += s[i++];
                    if (subs.find(var) != subs.end()) rhs = conv(subs[var], "");
                    else rhs = conv(1, var);
                    i--;
                }
                else if (c == ')') { // collapse
                    rhs = calc.top();
                    calc.pop();
                    while (collapse.top() == '+') {
                        collapse.pop();
                        vector<pair<int,vector<string>>> lhs = calc.top();
                        calc.pop();
                        add(rhs, lhs);
                    }
                    collapse.pop();
                }
                else { // number
                    int val = 0;
                    while (i < n && s[i] != ' ' && s[i] != ')') val = val*10 + s[i++]-'0';
                    rhs = conv(val, "");
                    i--;
                }
                if (!collapse.empty() && collapse.top() == '*') {
                    collapse.pop();
                    mult(calc.top(), rhs);
                }
                else calc.emplace(rhs);
            }
        }

        vector<pair<int,vector<string>>> res = calc.top();
        calc.pop();
        while (!calc.empty()) {
            add(res, calc.top());
            calc.pop();
        }

        auto comp = [&](const pair<int,vector<string>>& lhs, const pair<int,vector<string>>& rhs) {
            if (lhs.second.size() == rhs.second.size()) return lhs.second < rhs.second;
            return lhs.second.size() > rhs.second.size();
        };

        ranges::sort(res, comp);

        vector<string> output;
        output.reserve(res.size());
        for (auto& pr : res) {
            if (!pr.first) continue;
            string term = to_string(pr.first);
            for (string& var : pr.second) term += "*" + var;
            output.push_back(term);
        }
        return output;
    }
};
