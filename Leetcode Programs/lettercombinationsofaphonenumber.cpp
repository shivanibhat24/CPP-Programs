class Solution {
public:
    vector <char> v[15];
    char c[100];
    vector <string> res;
    void xuly(){
        v[2] = {'a', 'b', 'c'};
        v[3] = {'d', 'e', 'f'};
        v[4] = {'g', 'h', 'i'};
        v[5] = {'j', 'k', 'l'};
        v[6] = {'m', 'n', 'o'};
        v[7] = {'p', 'q', 'r', 's'};
        v[8] = {'t', 'u', 'v'};
        v[9] = {'w', 'x', 'y', 'z'};
    }
    void qlb16(int i,string s){
    int nums=s[i]-'0';
            if (nums<2|| nums>9 ) return;

    for (auto u:v[nums]){
        c[i]=u;
        if (i==s.size()-1){
            string tmp="";
            for (int k=1;k<s.size();k++){
                tmp+=c[k];
            }
            res.push_back(tmp);
        }
        else {
            qlb16(i+1,s);
        }
    } 
    }
    vector<string> letterCombinations(string digits) {
        xuly();
        digits = '0'+digits;
        qlb16(1,digits);
        return res;
    }
};
