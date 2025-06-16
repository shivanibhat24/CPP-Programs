class Solution {
public:
    string alphabetBoardPath(string target) {
        int r = 0;
        int c = 0;
        string ans;
        for(int i=0;i<target.size();i++){
            int r1 = (target[i]-'a')/5;
            int c1 = (target[i]-'a')%5;
            ans+=string(max(0,r-r1),'U')+
                 string(max(0,c-c1),'L')+
                 string(max(0,r1-r),'D')+
                 string(max(0,c1-c),'R')+'!';
            r=r1;
            c=c1;
        }
        return ans;
    }
};
