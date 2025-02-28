class Solution {
public:
    int maxPower(string s) {
      int ans = 1;
      int maxx = 1;
      char d;
      for(int i = 1; i<s.size() ; i++){
        d = s[i];
        if(s[i-1] == d){
            ans++;
            maxx = max(ans,maxx);
        }else{
            ans = 1;
        }
      }
      return maxx;  
    }
};
