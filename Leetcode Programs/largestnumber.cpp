class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> arr;
        auto cm=[&](string &s1, string &s2){ return s1+s2>s2+s1; };
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr),cm);
        string res;
        if (arr[0] == "0") {
            return "0";
        }
        for(auto s:arr)
            res+=s;
        return  res;
    }
};
