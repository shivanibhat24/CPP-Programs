class Solution {
public:
    int row(char &l){
        char w = tolower(l);
        if(w == 'q' || w == 'w' || w == 'e' || w == 'r' || w == 't' || w == 'y' || w == 'u'|| w == 'i' || w == 'o' || w == 'p') return 1;
        else if( w == 'a' || w == 's' || w == 'd'|| w == 'f' || w == 'g' || w == 'h' || w == 'j' || w == 'k' || w == 'l') return 2;
        return 3;
    }
    vector<string> findWords(vector<string>& words) {
         vector<string>r;
         for(string word : words){
            int f = 0 ,  s = 0 , t = 0;
            for(char ch : word){
                int r = row(ch);
                if(r==1) f++;
                else if(r == 2)s++;
                else if(r==3) t++;
            }
            if((f>0 && s == 0 && t == 0) || ( f == 0 && s > 0 && t == 0) || (f == 0 && s == 0 && t > 0))
            r.push_back(word);
         }
         return r;
    }
};
