class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int sum=0, iota=0;
        string s;
        string a= num1.substr(0,num1.find("+"));
        string b= num2.substr(0,num2.find("+"));
        string c= num1.substr(num1.find("+")+1,num1.find("i")-num1.find("+")-1);
        string d= num2.substr(num2.find("+")+1,num2.find("i")-num2.find("+")-1);
        sum = (stoi(a) * stoi(b)) - (stoi(c) * stoi(d));
        iota = (stoi(a) * stoi(d)) + (stoi(c) * stoi(b));
        s= to_string(sum) + "+" + to_string(iota) + "i";
        return s;
    }
};
