class Solution {
private:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }; 
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        int res=0, shortLen=0, extraLen=0;
        int missingChars=3; 
        if(n < 6)shortLen=6-n;
        bool hasDigit=1, hasUpper=1, hasLower=1;
        for(char ch : password){
                if(isdigit(ch) && hasDigit)missingChars--, hasDigit=0;
                if(isupper(ch) && hasUpper)missingChars--, hasUpper=0;
                if(islower(ch) && hasLower)missingChars--, hasLower=0;
            if(missingChars==0)break;    
        }
        if(n > 20)extraLen=n-20;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> min_q(cmp);
        int j = 0;
        for (int i = 1; i < n; i++) {
            while (i < n && password[j] == password[i])i++;  
            if(i-j >= 3)min_q.push(make_pair((i-j) % 3, i-j));  
         j = i;  
       }
        int len=extraLen;
        while (!min_q.empty() && len != 0) {
                int size=min_q.top().second - 1; 
                min_q.pop();
                min_q.push({size%3, size});
            len--;
        }
        priority_queue<int> max_q;
        while (!min_q.empty()) { 
            max_q.push(min_q.top().second);
            min_q.pop();
        }
        int replaces=0;
        while (!max_q.empty() && max_q.top() >= 3) {
            int len = max_q.top() - 3;
            max_q.pop();
            max_q.push(len);
            replaces++; 
        }
        res = extraLen + max(replaces, max(shortLen, missingChars));
     return res;
    }
};
