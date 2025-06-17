class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int i=2;
        int next=1;
        while(s.size()<n){
            if(s[i]=='2'){
                s.push_back(next+'0');
                s.push_back(next+'0');
                i=i+1;
            }
            else{
                s.push_back(next+'0');
                i=i+1;
            }
            next=3-next;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
        }
        return count;
    }
};
