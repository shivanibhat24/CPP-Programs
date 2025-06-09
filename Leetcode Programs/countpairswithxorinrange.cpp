struct BinaryTrie {
    std::vector<int> trie;
    int bits_count;
    BinaryTrie(const std::vector<int>& nums, int bits_count) 
        : trie(1, 0), 
          bits_count(bits_count) 
    {
        for(const auto& x: nums) {
            this->insert(x);
        }
    }
    void insert(int x) {
        int pointer = 0;
        this->trie[pointer]++;
        for(size_t mask = (1 << this->bits_count); mask > 0; mask >>= 1) {
            int bit = ((mask & x) != 0);
            pointer = 2 * pointer + 1 + bit;
            if(this->trie.size() <= pointer) {
                this->trie.resize(pointer + 1, 0);
            }
            this->trie[pointer]++;
        }
    }
    long long subtree_size(int pointer) {
        return (pointer >= this->trie.size() ? 0 : this->trie[pointer]);
    }
    long long count_xor_lower(int x, int bound) {
        long long answer = 0;
        int pointer = 0;
        for(size_t mask = (1 << this->bits_count); mask > 0; mask >>= 1) {
            int bit = ((mask & x) != 0);
            int bound_bit = ((mask & bound) != 0);
            if(bound_bit == 1) {
                answer += this->subtree_size(2 * pointer + 1 + bit);
            }
            if(bit == bound_bit) {
                pointer = 2 * pointer + 1; 
            } else {
                pointer = 2 * pointer + 2; 
            }
        }
        answer += this->subtree_size(pointer);
        return answer;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int max = *std::max_element(nums.begin(), nums.end());        
        size_t bits_count = 0;
        for(int y = std::max(high, max); y; y >>= 1) {
            ++bits_count;
        }
        BinaryTrie trie(nums, bits_count);
        long long answer = 0;
        for(const auto& x: nums) {
            answer += trie.count_xor_lower(x, high);
            answer -= trie.count_xor_lower(x, low - 1);
        }
        return answer / 2; 
    }
};
