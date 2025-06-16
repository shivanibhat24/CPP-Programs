class Solution {
public:
    string customSortString(string order, string s) {
        int n  = order.size();
        sort(s.begin(),s.end());
        string ans;
        for(int i =0; i<n; i++){
              if(s.find(order[i]) != std::string::npos){
                  for(int j = 0; j<200; j++){
                       if(order[i] == s[j]){
                           while(order[i] == s[j]){
                              ans.push_back(s[j]);
                              s[j] = '*';
                              j++;
                           }
                           break;
                       }
                  }
              }
        }
        for(int i =0; i<s.size(); i++){
              if(s[i] != '*'){
                  ans.push_back(s[i]);
              }
        }
        return ans;
    }
};
