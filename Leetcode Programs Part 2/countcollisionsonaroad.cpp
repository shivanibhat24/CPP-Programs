class Solution {
public:
    int countCollisions(string directions) {
        int i,c=0,l=0,r=directions.length()-1;
        while(l<directions.length() && directions[l]=='L') l++;
        while(r>=0 && directions[r]=='R') r--;
        for(i=l;i<=r;i++)
            if(directions[i]!='S') c++;
        return c;
    }
};
