class Solution {
public:
    int maxOperations(string s) {
        int ones=0;
        int ans=0;
        for(int i=0;i<s.size();i+=1){
            if(s[i]=='1')ones+=1;
            else if(i==0 || s[i-1]=='1')ans+=ones;
        }
        return ans;
    }
};
