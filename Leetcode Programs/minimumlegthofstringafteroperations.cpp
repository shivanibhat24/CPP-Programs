class Solution {
public:
    int minimumLength(string s) {
        int arr[26] = {0};
        for(char ch: s)
            arr[ch - 'a']++;
        int l = 0;
        for(int i = 0; i < 26; i++) {
            if(arr[i] > 0)
                l += (arr[i]&1)?1:2;
        }
        return l;
    }
};
