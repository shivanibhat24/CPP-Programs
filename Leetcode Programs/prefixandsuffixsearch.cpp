int t[700009][29],ts;
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        memset(t,0,sizeof(t[0])*ts),ts=8;
        for(int wi=0;wi<size(words);wi++){
            string&s=words[wi];
            for(int l=1;l<=min(7,int(size(s)));l++){
                int i=l;
                for(auto it=end(s)-i;it!=end(s);it++){
                    int&j=t[i][*it-'a'];
                    if(!j)j=ts++;
                    i=j;
                    t[i][26]=wi;
                }
                for(char x:s){
                    int&j=t[i][x-'a'];
                    if(!j)j=ts++;
                    i=j;
                    t[i][26]=wi;
                }
            }
        }
    }
    int f(string p, string s) {
        int i=size(s);
        for(auto x:s){
            i=t[i][x-'a'];
            if(!i)return -1;
        }
        for(auto x:p){
            i=t[i][x-'a'];
            if(!i)return -1;
        }
        return t[i][26];
    }
};
