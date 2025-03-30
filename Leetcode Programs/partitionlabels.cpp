class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map <char,int> mapa;
        unordered_set <char> set;
        for(int j = 0; j < s.size();j++){
            mapa[s[j]] = j;
        }
        int i = 0;
        vector<int> rez;
        int last = 0;
        for(int j = 0; j < s.size();j++){
            
            last = max(mapa[s[j]],last);
            

            if(last == j){
                rez.push_back(j - i + 1);
                i = j + 1;
            }
        }
        return rez;
    }
};
