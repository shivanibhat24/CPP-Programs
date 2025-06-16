class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
       int n = transactions.size();
        vector<tuple<string,int,int,string>> trans;
        trans.reserve(n);
        for (int i = 0; i < n; ++i) {
            const string& s = transactions[i];
            int p1 = s.find(',');
            int p2 = s.find(',', p1 + 1);
            int p3 = s.find(',', p2 + 1);
            string name = s.substr(0, p1);
            int time = stoi(s.substr(p1 + 1, p2 - (p1 + 1)));
            int amount = stoi(s.substr(p2 + 1, p3 - (p2 + 1)));
            string city = s.substr(p3 + 1);
            trans.emplace_back(name, time, amount, city);
        }
        unordered_map<string, vector<int>> hash;
        hash.reserve(n);
        for (int i = 0; i < n; ++i) {
            const string& name = get<0>(trans[i]);
            hash[name].push_back(i);
        }
        vector<bool> invalid(n, false);
        for (auto& kv : hash) {
            auto& name_transactions = kv.second;
            sort(name_transactions.begin(), name_transactions.end(),
                [&](int a, int b) {
                    return get<1>(trans[a]) < get<1>(trans[b]);
                });
            int m = name_transactions.size();
            for (int i = 0; i < m; ++i) {
                int idx1 = name_transactions[i];
                int time1 = get<1>(trans[idx1]);
                int amt1  = get<2>(trans[idx1]);
                if (amt1 > 1000) {
                    invalid[idx1] = true;
                }
                for (int j = i + 1; j < m; ++j) {
                    int idx2 = name_transactions[j];
                    int time2 = get<1>(trans[idx2]);
                    if (time2 - time1 > 60) {
                        break;
                    }
                    const string& city1 = get<3>(trans[idx1]);
                    const string& city2 = get<3>(trans[idx2]);
                    if (city1 != city2) {
                        invalid[idx1] = true;
                        invalid[idx2] = true;
                    }
                }
            }
        }
        vector<string> answer;
        answer.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (invalid[i]) {
                answer.push_back(transactions[i]);
            }
        }
        return answer;
    }
};
