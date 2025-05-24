class Solution {
public:
    static vector<int> findWordsContaining(vector<string>& words, char x) {
        const int n=words.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if (words[i].find(x)!=-1)
                ans.push_back(i);
        }
        return ans;
    }
};
