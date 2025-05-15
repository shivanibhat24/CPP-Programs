class Trie{
public:
    Trie* child[26] = {};
    bool isEnd = false;
};
class StreamChecker {
private:
    Trie* root;
    string stream;
    void addWord(Trie* root, string word){
        int n = word.size();
        stream = "";
        for(int i = n-1; i>=0; i--){
            if(root->child[word[i] - 'a'] == NULL) root->child[word[i] - 'a'] = new Trie();
            root = root->child[word[i] - 'a'];
        }
        root->isEnd = true;
    }
    
    bool searchStream(Trie* root){
        int n = stream.size();
        for(int i = n-1; i>=0; i--){
            if(root->child[stream[i] - 'a'] == NULL) return false;
            root = root->child[stream[i] - 'a'];
            if(root->isEnd == true) return true;
        }
        return false;
    }
    
public:
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for(auto word : words){
            addWord(root, word);
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        return searchStream(root);
    }
};
