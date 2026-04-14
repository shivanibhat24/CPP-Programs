static int keys[1 << 18];
static int vals[1 << 18];
static int res_arr[10005];
class Solution {
    static const int SIZE = 1 << 18;
    static const int MASK = SIZE - 1;

public:
    std::vector<int> findNumOfValidWords(std::vector<std::string>& words, std::vector<std::string>& puzzles) {
        std::memset(keys, 0, sizeof(keys));
        std::memset(vals, 0, sizeof(vals));

        for (const std::string& w : words) {
            int mask = 0;
            for (char ch : w) mask |= (1 << (ch - 'a'));
            
            if (__builtin_popcount(mask) <= 7) {
                unsigned int h = mask;
                h ^= h >> 16; h *= 0x85ebca6b; h ^= h >> 13; h *= 0xc2b2ae35; h ^= h >> 16;
                int pos = h & MASK;
                while (keys[pos] != 0 && keys[pos] != mask) {
                    pos = (pos + 1) & MASK;
                }
                keys[pos] = mask;
                vals[pos]++;
            }
        }
        int p_size = puzzles.size();
        for (int i = 0; i < p_size; ++i) {
            const std::string& p = puzzles[i];
            int firstBit = (1 << (p[0] - 'a'));
            int maskRemaining = 0;
            for (int j = 1; j < 7; ++j) {
                maskRemaining |= (1 << (p[j] - 'a'));
            }
            int count = 0;
            int submask = maskRemaining;
            do {
                int target = submask | firstBit;
                unsigned int h = target;
                h ^= h >> 16; h *= 0x85ebca6b; h ^= h >> 13; h *= 0xc2b2ae35; h ^= h >> 16;
                int pos = h & MASK;
                while (keys[pos] != 0) {
                    if (keys[pos] == target) {
                        count += vals[pos];
                        break;
                    }
                    pos = (pos + 1) & MASK;
                }
                submask = (submask - 1) & maskRemaining;
            } while (submask != maskRemaining);
            
            res_arr[i] = count;
        }

        // Возвращаем результат одним махом
        return std::vector<int>(res_arr, res_arr + p_size);
    }
};
