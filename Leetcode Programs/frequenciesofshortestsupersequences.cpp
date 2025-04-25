class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
        bitset<26> used;
        vector<int_fast8_t> base(26, 1);
        for (auto& w : words) {
            for (auto c : w) used[c - 'a'] = true;
            if (w[0] == w[1]) base[w[0] - 'a'] = 2;
        }
        vector<int> ul;
        for (int i = 0; i < 26; ++i) {
            if (used[i] && base[i] == 1) ul.push_back(i);
        }
        int usz = ul.size();
        vector<int> uidx(26, -1);
        for (int i = 0; i < usz; ++i)
            uidx[ul[i]] = i;
        vector<int> incoming(usz, 0);
        for (const auto& w : words) {
            if (w[0] == w[1]) continue;
            int a = w[0] - 'a', b = w[1] - 'a';
            if (uidx[a] == -1 || uidx[b] == -1) continue;
            incoming[uidx[b]] |= (1 << uidx[a]);
        }
        int mn = INT_MAX;
        vector<int> valid_masks;
        int total = 1 << usz;
        for (int mask = 0; mask < total; ++mask) {
            int upgr = __builtin_popcount(mask);
            if (upgr > mn) continue;
            int s_mask = ((1 << usz) - 1) & (~mask);
            int rem = s_mask;
            bool acyclic = true;
            while (rem) {
                int found = -1;
                for (int i = 0; i < usz; ++i) {
                    if ((rem >> i) & 1) {
                        if ((incoming[i] & rem) == 0) {
                            found = i;
                            break;
                        }
                    }
                }
                if (found == -1) {
                    acyclic = false;
                    break;
                }
                rem &= ~(1 << found);
            }
            if (!acyclic) continue;
            if (upgr < mn) {
                mn = upgr;
                valid_masks.clear();
            }
            valid_masks.push_back(mask);
        }
        vector<vector<int>> res;
        for (auto mask : valid_masks) {
            vector<int> freq(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (used[i] && base[i] == 2) freq[i] = 2;
            }
            for (int i = 0; i < usz; ++i) {
                int letter = ul[i];
                freq[letter] = 1 + ((mask >> i) & 1);
            }
            res.push_back(freq);
        }
        return res;
    }
};
