class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int max_len = 0;
        vector<int> count(26,0);
        int max_present = 0;
        for (int right = 0; right<s.size(); right++){
            count[s[right]-'A']++;
            max_present = max(max_present, count[s[right]-'A']);
            //ghi nhận cửa sổ
            while (right-left+1-max_present>k){        // cửa sổ không thoả
                count[s[left]-'A']--;
                left++;
            }
            max_len = max(max_len, right-left+1);
        }
        return max_len;
    }
};
