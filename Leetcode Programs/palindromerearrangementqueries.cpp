class Solution {
public:
    static constexpr long long kBas = 29;
    static constexpr long long kMod = 1e9 + 7;
    static constexpr int kNCh = 'z' - 'a' + 1;
    static vector<long long> pow;
    vector<bool> canMakePalindromeQueries(const string& line, vector<vector<int>>& queries) {
        int N = line.length() / 2;
        string A(line.substr(0, N));
        string B(line.substr(N, N));
        reverse(B.begin(), B.end());
        pow.resize(N + 1);
        pow[0] = 1;
        for (int i = 1; i <= N; ++i)
            pow[i] = (pow[i - 1] * kBas) % kMod;
        struct StringIndex {
            int N;
            const char* data;
            vector<int> rabin_karp;
            vector<array<int, kNCh>> prefix_2_char2count; 
            StringIndex(const string& s)
                    : N(s.length())
                    , data(s.c_str())
                    , rabin_karp(N + 1)
                    , prefix_2_char2count(N + 1) {
                for (int i = 0; i < N; ++i) {
                    rabin_karp[i + 1] = (rabin_karp[i] * kBas + data[i]) % kMod;
                    prefix_2_char2count[i + 1] = prefix_2_char2count[i];
                    ++prefix_2_char2count[i + 1][data[i] - 'a'];
                }
            }
            long long get_rabin_karp(int b_endg_in, int end_ex) const {
                return ((rabin_karp[end_ex] - rabin_karp[b_endg_in] * pow[end_ex - b_endg_in]) % kMod + kMod) % kMod;
            }
            int get_char_count(char c, int b_endg_in, int end_ex) const {
                c -= 'a';
                return prefix_2_char2count[end_ex][c] - prefix_2_char2count[b_endg_in][c];
            }
            bool char_set_equal(const StringIndex& that, int b_endg_in, int end_ex) const {
                for (char c = 'a'; c <= 'z'; ++c)
                    if (this->get_char_count(c, b_endg_in, end_ex) !=
                            that.get_char_count(c, b_endg_in, end_ex))
                        return false;
                return true;
            }
            bool char_set_ge(int b_endg_in, int end_ex,
                                const StringIndex& that, int that_b_endg_in, int that_end_ex) const {
                for (char c = 'a'; c <= 'z'; ++c)
                    if (this->get_char_count(c, b_endg_in, end_ex) <
                            that.get_char_count(c, that_b_endg_in, that_end_ex))
                        return false;
                return true;
            }
        };
        const StringIndex index_a(A);
        const StringIndex index_b(B);
        vector<bool> res(queries.size());
        if (!index_a.char_set_equal(index_b, 0, N)) return res;
        transform(
            queries.begin(), queries.end(), res.begin(),
            [&index_a, &index_b, N](const auto& query) {
                int a_beg = query[0];
                int a_end = query[1];
                int b_beg = 2 * N - 1 - query[3]; 
                int b_end = b_beg + query[3] - query[2];
                const StringIndex& idx_a = a_beg <= b_beg ? index_a : index_b;
                const StringIndex& idx_b = a_beg <= b_beg ? index_b : index_a;
                if (a_beg > b_beg) {
                    swap(a_beg, b_beg);
                    swap(a_end, b_end);
                }
                if (idx_a.get_rabin_karp(0, a_beg) != idx_b.get_rabin_karp(0, a_beg))
                    return false;
                int end = max(a_end, b_end);
                if (idx_a.get_rabin_karp(end + 1, N) != idx_b.get_rabin_karp(end + 1, N)) return false;
                if (a_end < b_beg) { 
                    if (idx_a.get_rabin_karp(a_end + 1, b_beg) !=
                            idx_b.get_rabin_karp(a_end + 1, b_beg))
                        return false;
                    if (!idx_a.char_set_equal(idx_b, a_beg, a_end + 1)) return false;
                    if (!idx_a.char_set_equal(idx_b, b_beg, b_end + 1)) return false;
                }
                else if (a_end < b_end) { 
                    if (!idx_a.char_set_ge(a_beg, a_end + 1, idx_b, a_beg, b_beg)) return false;
                    if (!idx_b.char_set_ge(b_beg, b_end + 1, idx_a, a_end + 1, b_end + 1)) return false;
                }
                return true;
            });
        return res;
    }
};
vector<long long> Solution::pow;
