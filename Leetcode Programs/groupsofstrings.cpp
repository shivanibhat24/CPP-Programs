class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        const int N = words.size();
        struct DisjSet {
            vector<int> repr, rank;
            DisjSet(int N) : repr(N), rank(N) { iota(repr.begin(), repr.end(), 0); }
            int get_repr(int a) { return repr[a] == a ? a : repr[a] = get_repr(repr[a]); };
            void merge(int a, int b) {
                a = get_repr(a);
                b = get_repr(b);
                rank[a] += rank[a] == rank[b];
                if (rank[a] > rank[b]) 
                    repr[b] = a;
                else
                    repr[a] = b;
            };
        };
        DisjSet disj_set(N);
        for (int i = 0; i < N; ++i) {
            int mask = str2mask(words[i]);
            if (mask_add1_2_last_idx[mask] >= mask_add1_2_last_idx_offset)
                disj_set.merge(i, mask_add1_2_last_idx[mask] - mask_add1_2_last_idx_offset);
            mask_add1_2_last_idx[mask] = i + mask_add1_2_last_idx_offset;
            for (int bp = 0; bp < kAlphaSize; ++bp) {
                int b = 1 << bp;
                if (mask & b) {
                    int m = mask ^ b;
                    if (mask_add1_2_last_idx[m] >= mask_add1_2_last_idx_offset)
                        disj_set.merge(i, mask_add1_2_last_idx[m] - mask_add1_2_last_idx_offset);
                    mask_add1_2_last_idx[m] = i + mask_add1_2_last_idx_offset;
                }
            }
        }
        mask_add1_2_last_idx_offset += N + 1;
        vector<int> repr2count(N);
        for (int i = 0; i < N; ++i)
            ++repr2count[disj_set.get_repr(i)];
        int groups_count = 0;
        int groups_max = 0;
        for (int c : repr2count) {
            groups_count += c > 0;
            groups_max = max(groups_max, c);
        }
        return { groups_count, groups_max };
    }
private:
    static constexpr char kAlphaBeg = 'a';
    static constexpr int kAlphaSize = 'z' - kAlphaBeg + 1;
    static array<int, 1 << kAlphaSize> mask_add1_2_last_idx;
    static int mask_add1_2_last_idx_offset;
    static inline int str2mask(const string& s) {
        int m = 0;
        for (char c : s)
            m |= 1 << (c - kAlphaBeg);
        return m;
    }
};
array<int, 1 << Solution::kAlphaSize> Solution::mask_add1_2_last_idx{};
int Solution::mask_add1_2_last_idx_offset = 1;
