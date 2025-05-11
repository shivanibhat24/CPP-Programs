class Solution {
public:
    bool threeConsecutiveOdds(const vector<int>& arr) {
        return search_n(arr.begin(), arr.end(), 3, 0,[](int a, int){ return a & 1;}) != arr.end();
    }
};
