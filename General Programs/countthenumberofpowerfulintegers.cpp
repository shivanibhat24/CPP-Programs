class Solution {
    #define ll long long
    ll dp[17][2];

    // Compare suffix numerically
    bool checkSubtract(string& fin, ll& finish_digits, string& s, int& limit) {
        if (finish_digits < s.size()) return false;

        string suffix_of_fin = fin.substr(finish_digits - s.size());
        bool subtract = stoll(suffix_of_fin) < stoll(s);

        for (int i = 0; subtract == true && i < finish_digits - s.size(); ++i) {
            if ((fin[i] - '0') > limit) {
                subtract = false;
                break;
            }
        }
        return subtract;
    }

    //Digit DP
    ll countValidNumbers(string& number, ll curr_idx, ll& max_digits, bool is_tight, int& limit, string& s) {
        if (curr_idx == max_digits) return 1; // A valid sequence has been formed
        if (dp[curr_idx][is_tight] != -1) return dp[curr_idx][is_tight];

        ll low = 0, high;

        if (curr_idx >= (max_digits - s.size())) {
            ll idx = curr_idx - (max_digits - s.size());
            low = high = s[idx] - '0';
        } else {
            high = is_tight ? min<ll>(limit, number[curr_idx] - '0') : limit;
        }

        ll count = 0;
        for (ll digit = low; digit <= high; ++digit) {
            bool new_tight = is_tight && (digit == number[curr_idx] - '0');
            count += countValidNumbers(number, curr_idx + 1, max_digits, new_tight, limit, s);
        }

        return dp[curr_idx][is_tight] = count;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        ll suffix_number = stoll(s);
        string fin = to_string(finish);
        string beg = to_string(start - 1);

        ll finish_digits = fin.size();
        ll start_digits = (start <= 1) ? 0 : beg.size();

        // Finish
        memset(dp, -1, sizeof(dp));
        ll one_to_finish = 0;
        if (finish >= suffix_number) {
            one_to_finish = countValidNumbers(fin, 0, finish_digits, true, limit, s);
            if (checkSubtract(fin, finish_digits, s, limit))
                one_to_finish--;
        }

        // Start - 1
        memset(dp, -1, sizeof(dp));
        ll one_to_start = 0;
        if (suffix_number < start && start > 1) {
            one_to_start = countValidNumbers(beg, 0, start_digits, true, limit, s);
            if (checkSubtract(beg, start_digits, s, limit))
                one_to_start--;
        }

        return one_to_finish - one_to_start;
    }
};
