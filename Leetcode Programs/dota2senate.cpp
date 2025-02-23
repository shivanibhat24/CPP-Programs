class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> radiant, dire;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            int rIndex = radiant.front();
            int dIndex = dire.front();
            
            if (rIndex < dIndex) {
                radiant.pop();
                dire.pop();
                radiant.push(rIndex + n);
            } else {
                dire.pop();
                radiant.pop();
                dire.push(dIndex + n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};
