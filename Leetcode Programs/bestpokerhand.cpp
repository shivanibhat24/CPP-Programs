class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if ((suits[0] == suits[1]) and (suits[1] == suits[2]) and
            (suits[2] == suits[3]) and (suits[3] == suits[4])) {
            return "Flush";
        }
        sort(ranks.begin(), ranks.end());
        for (int i = 0; i < 3; ++i) {
            if ((ranks[i] == ranks[i + 1]) and (ranks[i + 1] == ranks[i + 2])) {
                return "Three of a Kind";
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (ranks[i] == ranks[i + 1]) {
                return "Pair";
            }
        }
        return "High Card";
    }
};
