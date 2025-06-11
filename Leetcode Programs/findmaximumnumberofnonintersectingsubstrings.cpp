class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.length();
        int len = 0;
        vector<int> nums(26, -1);
        for (int i = 0; i < n; i++) {
            int j = word[i] - 'a';
            if (nums[j] != -1 && i - nums[j] + 1 >= 4) {
                len++;
                for (int i = 0; i < 26; i++)
                    nums[i] = -1;
            } else {
                if (nums[j] == -1)
                    nums[j] = i;
            }
        }
        return len;
    }
};
