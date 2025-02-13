class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        auto isValid = [] (const string& h, const string& m){ return h < "24" && m < "60"; };
        sort(begin(arr), end(arr), greater<int>());
        do{ 
            const string h = to_string(arr[0]) + to_string(arr[1]);
            const string m = to_string(arr[2]) + to_string(arr[3]);
            if(isValid(h, m)) return h + ":" + m;
        }while(prev_permutation(begin(arr), end(arr)));
        return "";
    }
};
