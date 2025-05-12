class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++) 
            pos[row[i]] = i;
        int swaps = 0;
        for (int i = 0; i < n; i += 2) {
            int x = row[i];
            int want = x ^ 1;
            if (row[i + 1] != want) {
                swaps++;
                int p = pos[want];
                pos[row[i + 1]] = p;
                row[p] = row[i + 1];
                row[i + 1] = want;
                pos[want] = i + 1;
            }
        }
        return swaps;
    }
};
