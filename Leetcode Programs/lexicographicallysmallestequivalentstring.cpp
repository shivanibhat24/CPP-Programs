class Solution {
    int pa[26];
public:
    void init(){
        for(int i=0;i<26;i++)pa[i]=i;
    }
    int find(int n){
        if(pa[n]==n)return n;
        return pa[n]=find(pa[n]);
    }
    void unite(int x,int y){
        int px=find(x),py=find(y);
        if(px>py)swap(px,py);
        pa[py]=px;
    }
    string smallestEquivalentString(string_view s1, string_view s2, string& baseStr) {
        init();
        for(int i=0;i<s1.size();i++){
            unite(s1[i]-'a',s2[i]-'a');
        }
        for(char& c:baseStr){
            c=find(c-'a')+'a';
        }
        return baseStr;
    }
};
