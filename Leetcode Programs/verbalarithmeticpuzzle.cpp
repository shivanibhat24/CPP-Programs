class Solution
{
public:
    template <class It, class Val>
    static int index(It &iterable, Val val)
    {
        int pos = 0;
        for (auto x : iterable)
        {
            if (val == x)
            {
                return pos;
            }
            ++pos;
        }
        return -1;
    }
    bool isSolvable(vector<string> &words, string result)
    {
        auto terms = words;
        terms.push_back(result);

        auto potential_leading_zeros_set = set<char>();
        auto any_digit_set = set<char>();
        for (auto t : terms)
        {
            if (t.size() > 1)
                potential_leading_zeros_set.insert(t[0]);
            for (auto c : t)
                any_digit_set.insert(c);
        }
        for (auto c : potential_leading_zeros_set)
            any_digit_set.erase(c);

        auto chars = array<char, 10>();
        auto plz_end = (size_t)0;
        for (auto c : potential_leading_zeros_set)
            chars[plz_end++] = c;
        auto ad_end = plz_end;
        for (auto c : any_digit_set)
            chars[ad_end++] = c;

        auto weights = array<int, 10>();
        for (auto x : words)
        {
            auto e = 1;
            reverse(x.begin(), x.end());
            for (auto c : x)
            {
                weights[index(chars, c)] += e;
                e *= 10;
            }
        }
        {
            auto x = result;
            auto e = 1;
            reverse(x.begin(), x.end());
            for (auto c : x)
            {
                weights[index(chars, c)] -= e;
                e *= 10;
            }
        }

        for (auto i = (size_t)0; i < plz_end; ++i)
            if (weights[i] != 0)
                nz_weigths[nzw_plz_end++] = weights[i];
        nzw_ad_end = nzw_plz_end;
        for (auto i = plz_end; i < ad_end; ++i)
            if (weights[i] != 0)
                nz_weigths[nzw_ad_end++] = weights[i];

        if (nzw_ad_end == 0)
        {
            return true;
        }

        w0 = nz_weigths[0];
        w0_min_d = nzw_plz_end == 0 ? 0 : 1;

        return recurse(1, (1 << 10) - 1, 0);
    }
    bool recurse(size_t i, int available, int sum)
    {
        if (i >= nzw_ad_end)
        {
            if (sum % w0 != 0)
                return false;
            auto d = -sum / w0;
            if (d < w0_min_d || d > 9 || (available & 1 << d) == 0)
                return false;
            return true;
        }
        auto w = nz_weigths[i];
        auto choices = i >= nzw_plz_end ? available : available & ~1;
        while (choices > 0)
        {
            auto d = choices & -choices;
            if (recurse(i + 1, available ^ d, sum + __builtin_ctz(d) * w))
                return true;
            choices ^= d;
        }
        return false;
    }
    size_t nzw_plz_end, nzw_ad_end;
    array<int, 10> nz_weigths;
    int w0, w0_min_d;
};
