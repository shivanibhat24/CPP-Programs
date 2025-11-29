class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> seen;
        for(auto const& word : words){
            seen.insert(word);
        }

        string ans = "";
        for(auto const& word : words){
            if(word.size() > ans.size() || (word.size() == ans.size() && word < ans)){
                bool found = true;
                for(int i = 1; i < word.size(); i++){
                    if(seen.count(word.substr(0, i)) == 0){
                        found = false;
                    }
                }
                if(found){                
                    ans = word;
                }
            }
        }

        return ans;
    }
};
