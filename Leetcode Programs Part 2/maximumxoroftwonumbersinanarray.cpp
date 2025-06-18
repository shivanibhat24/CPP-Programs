struct BitTrie {
    array<BitTrie*, 2> nodes{};
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int totalOR =
            std::accumulate(nums.begin(), nums.end(), 0,
                            [](auto acc, auto curr) { return acc | curr; });
        int mostSigBitPos = 0;
        while (totalOR != 0) {
            totalOR >>= 1;
            ++mostSigBitPos;
        }
        vector<BitTrie> pool;
        pool.reserve(3'000'000);
        pool.emplace_back();
        BitTrie* root = &pool.back();
        int maxXOR = 0;
        for (auto const& num : nums) {
            BitTrie* numNode = root;
            BitTrie* inverseNode = root;
            int currMaxXOR = 0;
            for (int i = mostSigBitPos - 1; i >= 0; --i) {
                int numBit = num >> i & 1;
                int inverseBit = numBit ^ 1;
                if (!numNode->nodes[numBit]) {
                    pool.emplace_back();
                    numNode->nodes[numBit] = &pool.back();
                }
                numNode = numNode->nodes[numBit];
                if (inverseNode->nodes[inverseBit]) {
                    currMaxXOR |= 1 << i;
                    inverseNode = inverseNode->nodes[inverseBit];
                } else if (inverseNode->nodes[numBit]) {
                    inverseNode = inverseNode->nodes[numBit];
                } else {
                    break;
                }
            }
            maxXOR = std::max(maxXOR, currMaxXOR);
        }

        return maxXOR;
    }
};
