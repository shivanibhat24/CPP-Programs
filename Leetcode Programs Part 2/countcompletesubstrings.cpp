class Solution {
public:
     int solve(string &s, int k, int start, int end) {
        int ans = 0;
        for (int curr = 1; curr<=26 && curr * k <= end - start + 1; curr++) {
           vector<int> mp(26,0);
            int i = start;
            int cnt = 0;
            int window=curr*k;
            for (int j = start; j <= end; j++) {
                int jdx = s[j] - 'a';
                mp[jdx]++;
                if (mp[jdx] == k)
                    cnt++;
                else if (mp[jdx] == k + 1)
                    cnt--;

                if (j - i + 1 > window) {
                    int idx = s[i] - 'a';
                    if (mp[idx] == k)
                        cnt--;
                    else if (mp[idx] == k + 1)
                        cnt++;
                    mp[idx]--;
                    i++;
                }

                if (cnt == curr && j - i + 1 == window) {
                    ans++;
                }
            }
        }
        return ans;
    }

    int countCompleteSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;int start = 0;

        for (int i = 1; i <= n; i++) {
            if (i == n || abs(s[i] - s[i - 1]) > 2) {
                ans += solve(s, k, start, i - 1);
                start = i;
            }
        }

        return ans;
    }
};
