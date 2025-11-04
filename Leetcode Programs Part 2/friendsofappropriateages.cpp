class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (int age : ages) count[age]++;
        int ans = 0;
        for (int ageA = 0; ageA <= 120; ++ageA) {
            int countA = count[ageA];
            if (countA == 0) continue;
            for (int ageB = 0; ageB <= 120; ++ageB) {
                int countB = count[ageB];
                if (countB == 0) continue;
                if (ageB <= 0.5 * ageA + 7) continue;
                if (ageB > ageA) continue;
                if (ageB > 100 && ageA < 100) continue;
                ans += countA * countB;
                if (ageA == ageB)
                    ans -= countA;
            }
        }
        return ans;        
    }
};
