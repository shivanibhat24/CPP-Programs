class Solution {
    public:
    string clearStars(string s) {
        priority_queue<char,vector<char>,greater<char>> pq;
        vector<vector<int>> indices (26, vector<int>());
        char ch;
        for (int i = 0;i<s.size();i++){
            if (s[i] == '*'){
                ch = pq.top();
                s[indices[ch - 'a'].back()] = '!';
                indices[ch - 'a'].pop_back();
                if (indices[ch - 'a'].size() == 0){  
                    pq.pop();
                }
				continue;
            }
            if (indices[s[i] - 'a'].size() == 0){  
                pq.push(s[i]);
            }
            indices[s[i] - 'a'].push_back(i);
        }
        string res = "";
        for (char c: s){
            if (c >= 'a') { 
                res += c; 
            }
        }
        return res;
    }
};
