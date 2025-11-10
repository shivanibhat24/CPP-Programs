class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> finish;
        for (const auto& f: flowers) {
            start.push_back(f[0]);
            finish.push_back(f[1]+1);
        }
        const int f_cnt = flowers.size();
        sort(begin(start), end(start));
        sort(begin(finish), end(finish));
        vector<int> time;
        vector<int> cnt;
        for (int i=0, j=0, t=0, f=0, s=start[i], e=finish[i]; i<f_cnt || j<f_cnt;) {
            int updated {};
            if (s == t) {
                ++f;
                ++i;
                s = i < f_cnt ? start[i] : numeric_limits<int>::max();
                updated = 1;
            }
            if (e == t) {
                --f;
                ++j;
                e = j < f_cnt ? finish[j] : numeric_limits<int>::max();
                updated = 1;
            }
            if (!updated) {
                time.push_back(t);
                cnt.push_back(f);
                t = min(s, e);
            }
        }
        time.push_back(finish.back());
        cnt.push_back(0);
        vector<int> res;
        for (int p: people) {
            const int idx = (upper_bound(begin(time), end(time), p) - begin(time))-1;
            res.push_back(cnt[idx]);
        }
        return res;
    }
};
