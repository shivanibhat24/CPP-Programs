 class Solution {
public:
 int monotoneIncreasingDigits(int N) {
     if(N < 10){
         return N;
     }
     string s = to_string(N);
     int index = s.length();
     int i;
     for(i = index -1 ; i > 0; i--){
         if(s[i-1] > s[i]){
             s[i-1]--;
             index = i; 
         }
     }
     for(i = index; i < s.length(); i++){
         s[i] = '9';
     }
     N = stoi(s);
     return N;
 }
};
