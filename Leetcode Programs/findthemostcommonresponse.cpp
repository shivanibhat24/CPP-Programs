const int N=26, M=1000;
string s="";
int f=0;
struct Trie {
    Trie* next[N];
    int cnt=0;
    Trie() {
        fill(next, next+N, (Trie*)NULL);
    }
    void insert(string& word) {
        Trie* Node=this;
        for(char c: word){
            int i=c-'a';
            if(Node->next[i]==NULL)
                Node->next[i]=new Trie();
            Node=Node->next[i];
        }
        int k=++Node->cnt;
        if (k>f){
            s=word;
            f=k;
        }
        else if (k==f && word<s) s=word;
    }
};
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        const int n=responses.size();
        f=0, s="";
        Trie trie;
        for(int i=0; i<n; i++){
            auto& w=responses[i];
            sort(w.begin(), w.end());
            const int wz=w.size();
            trie.insert(w[0]);
            for(int j=1; j<wz; j++)
                if (w[j]!=w[j-1]) trie.insert(w[j]);
        }
        return s;
    }
};
