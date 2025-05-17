class Solution {
public:
    int numberOfWays(const string& s, const string& t, long long k) {
        const int L = s.length();
        if (t.length() != s.length()) return 0;
        auto [head_len, period_len] = get_head_period(s, t);
        if (head_len < 0) return 0; 
        assert(L % period_len == 0);
        int n = L / period_len;
        DiagMatr trans(n - 1, n, period_len);
        DiagMatr ktrans = q_matr_exp(trans, k);
        return head_len == 0 ? ktrans.d : ktrans.b;
    }
private:
    static constexpr long long kMod = 1e9 + 7;
    pair<int, int> get_head_period(const string& s, const string& p) {
        const int L = s.length();
        const int M = 2 * L;
        string txt(M, ' ');
        copy(s.begin(), s.end(), txt.begin());
        copy(s.begin(), s.end(), txt.begin() + L);
        { 
            int match_pos_1st = txt.find(p);
            if (match_pos_1st == string::npos) return { -1, -1 };
            int match_pos_2nd = txt.find(p, match_pos_1st + 1);
            return { match_pos_1st, match_pos_2nd < 0 ? L : match_pos_2nd - match_pos_1st };
        }
        vector<int> lsp(L);
        for (int i = 1, j = 0; i < L; ++i) {
            while (j > 0 && p[j] != p[i])
                j = lsp[j - 1];
            lsp[i] = j += p[j] == p[i];
        }
        int match_pos_1st = -1;
        int match_pos_2nd = -1;
        for (int i = 0, j = 0; i < M; ++i) {
            while (j > 0 && p[j] != txt[i])
                j = lsp[j - 1];
            j += p[j] == txt[i];
            if (j == L) {
                if (match_pos_1st < 0) {
                    match_pos_1st = i + 1 - L;
                } else {
                    match_pos_2nd = i + 1 - L;
                    break;
                }
            }
        }
        if (match_pos_1st < 0) return { -1, -1 };
        if (match_pos_2nd < 0) return { match_pos_1st, L };
        return { match_pos_1st, match_pos_2nd - match_pos_1st };
    }
    struct DiagMatr {
        DiagMatr(long long d, long long b, long long sz) : d(d), b(b), sz(sz) {}
        const DiagMatr& operator*=(const DiagMatr& other) {
            assert(this->sz == other.sz);
            long long a = this->d, B = this->b, c = other.d, D = other.b;
            long long x = (a * c + (sz - 1) * B % kMod * D) % kMod;
            long long Y = (a * D + c * B + (sz - 2) * B % kMod * D) % kMod;
            d = x;
            b = Y;
            return *this;
        }
        const DiagMatr& operator=(long long d) {
            this->d = d;
            this->b = 0;
            return *this;
        }
        long long d = 0;  
        long long b = 0; 
        long long sz = 0;
    };
    template<typename T>
    T q_matr_exp(T b, long long p) { 
        T res(b);
        res = 1;
        for (; p; p >>= 1) {
            if (p & 1)
                res *= b;
            b *= b;
        }
        return res;
    }
};
