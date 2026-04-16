class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letterCount(26, 0);
        for (char c : letters) {
            letterCount[c - 'a']++;
        }
        return dfs(words, letterCount, score, 0);
    }

private:
    int dfs(vector<string>& words, vector<int>& letterCount, vector<int>& score, int index) {
        if (index == words.size()) {
            return 0;
        }

        int maxScore = dfs(words, letterCount, score, index + 1); // Skip the current word

        bool canUse = true;
        int wordScore = 0;
        for (char c : words[index]) {
            if (letterCount[c - 'a'] == 0) {
                canUse = false;
            }
            letterCount[c - 'a']--;
            wordScore += score[c - 'a'];
        }

        if (canUse) {
            maxScore = max(maxScore, wordScore + dfs(words, letterCount, score, index + 1));
        }

        for (char c : words[index]) { // Backtrack
            letterCount[c - 'a']++;
        }

        return maxScore;
    }
};
