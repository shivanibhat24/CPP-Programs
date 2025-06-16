class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int prev = 0;
        int curr = 0;
        int result = 0;
        char prev_op = '+';
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                curr = 10 * curr + (s[i] - '0');
            }
            if((!isdigit(s[i]) && s[i] != ' ') || i == n-1){
                if(prev_op == '*'){
                    prev = prev * curr;
                }
                if(prev_op == '/'){
                    prev = prev / curr; 
                }
                if(prev_op == '+' || prev_op == '-'){
                    result += prev;
                    prev = (prev_op == '-') ? -curr : curr;
                }
                prev_op = s[i];
                curr = 0;
            }
        }
        return result + prev;
    }
};
