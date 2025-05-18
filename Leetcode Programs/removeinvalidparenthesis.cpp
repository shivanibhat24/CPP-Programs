class Solution {
private:
    vector<string> res;

public:
    vector<string> removeInvalidParentheses(string s) {
        helper(s, 0, 0, {'(', ')'});
        return res;
    }

    void helper(string s, int left, int right, const vector<char>& para){
        int len=s.length();
        int counter=0;
        // Analysis
        //  "()())()"
        while(right<len){
            char ch= s[right];
            if(ch== para[0]){
                counter++;
            }
            else if(ch==para[1]){
                counter--;
            }
            if(counter< 0){
                break;
            }
            right++;

        }

        // Case 1
        if(counter<0){
            while(left<=right){
                char ch= s[left];
                if(ch!= para[1] || (left>0 && s[left]==s[left-1])){
                    left++;
                    continue;
                }
                // "(())()"
                s.erase(left,1);
                helper(s,left,right,para);
                s.insert(s.begin()+left, para[1]);
                left++;

            }
        }
        // Case 2
        else if(counter>0){
            reverse(s.begin(),s.end());
            helper(s,0,0,{')','(' });
        }
        // Case 3
        else{
            res.push_back(para[0]=='('? s : string(s.rbegin(), s.rend()));
        }
    }
    
};
