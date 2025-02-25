class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const auto [min_spell_it, max_spell_it] = std::ranges::minmax_element(spells);
        const auto min_spell = static_cast<long long>(*min_spell_it);
        const auto max_spell = static_cast<long long>(*max_spell_it);        
        const auto n = static_cast<size_t>(max_spell - min_spell + 1);
        const auto mem_size = n * sizeof(int);
        int* counts = static_cast<int*>(alloca(mem_size));
        memset(counts, 0, mem_size);
        for (const long long potion : potions) {
            const auto target = max(min_spell, (success + potion - 1) / potion);
            if (target <= max_spell)
                counts[target - min_spell]++;
        }
        partial_sum(counts, counts + n, counts);
        for (int& spell : spells)
            spell = counts[spell - min_spell];
        return spells;
    }
};
