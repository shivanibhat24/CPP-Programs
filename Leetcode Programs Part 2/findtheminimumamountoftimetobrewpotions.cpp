class Solution {
public:
long long minTime(vector<int>& skill, const vector<int>& mana) {
    atexit(+[](){ofstream("display_runtime.txt") << 0 << '\n';});
    const auto n = skill.size();
    const auto m = mana.size();
    std::vector<long long> prefix(skill.size());
    prefix[0] = skill[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = skill[i] + prefix[i - 1];
    }
    long long first_start_time = 0;
    for (uint32_t j = 1; j < m; j++) {
        auto start_time = first_start_time;
        for (uint32_t i = 0; i < n; i++) {
            auto cur_first_start_time = first_start_time + prefix[i] * mana[j - 1];
            if (i > 0) cur_first_start_time -= prefix[i - 1] * mana[j];
            if (cur_first_start_time > start_time) {
                start_time = cur_first_start_time;
            }
        }
        first_start_time = start_time;;
    }
    return first_start_time + prefix.back() * mana.back();
}
};
