class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        if(n1 < n2) return addStrings(num2,num1);
        int first=n1-1,second=n2-1;
        string ans;
        int res=0,carry=0;
        while(second >= 0){
            res=0;
            res+=(num1[first]-'0')+(num2[second]-'0')+carry;
            carry=res/10;
            ans+=(res%10)+'0';
            first--;
            second--;
        }
        while(first >= 0){
            res=0;
            res+=(num1[first]-'0')+carry;
            carry=res/10;
            ans+=(res%10)+'0';
            first--;
        }
        if(carry)
         ans+=(carry%10)+'0';        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
