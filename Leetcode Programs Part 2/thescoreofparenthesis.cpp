class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<char>st1;
        stack<pair<int,int>>st2;
        for(int i=0; i<n ;i++){
            if(s[i]=='('){
                st1.push('(');
            }
            else{
                int val = st1.size();
                st1.pop();
                if(st2.empty() || st2.top().second<val){
                    st2.push({1,val});
                }
                else if(st2.top().second == val){
                    int curr =1;
                    while( !st2.empty() && st2.top().second == val){
                        curr += st2.top().first;
                        st2.pop();
                        
                    }
                    st2.push({curr, val});
                }
                else{
                    int topval = st2.top().first;
                    st2.pop();
                    topval = topval*2;
                    while(!st2.empty() && st2.top().second == val){
                        topval += st2.top().first;
                        st2.pop();
                    }
                    st2.push({topval,val});
                }
            }
        }
        return st2.top().first;        
    }
};
