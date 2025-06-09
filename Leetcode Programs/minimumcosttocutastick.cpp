using namespace std;
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = n;
        n = cuts.size() - 2;
        int d[102][102] = {};
        for (int i = 1; i <= n; i++)
            d[i][i] = cuts[i + 1] - cuts[i - 1];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j + i <= n; j++) {
                d[j][j + i] = 1000000000;
                for (int k = j + 1; k < j + i; k++)
                    d[j][j + i] = min(d[j][j + i], d[j][k - 1] + d[k + 1][j + i]);
                d[j][j + i] = min(d[j][j + i], min(d[j + 1][j + i], d[j][j + i - 1]));
                d[j][j + i] += cuts[j + i + 1] - cuts[j - 1];
            }
        }
        return d[1][n];
    }
};
