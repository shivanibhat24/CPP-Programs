namespace {
    auto makePrimeFactors() {
        static constexpr int MAX_N = 1'000'000;
        std::vector<bool> isPrime(MAX_N, true);
        std::vector<std::vector<int>> primeFactors(MAX_N);
        for (int n = 2; n <= MAX_N; ++n) {
            if (isPrime[n - 1]) {
                primeFactors[n - 1].push_back(n);
                for (int coef = 2; coef * n <= MAX_N; ++coef) {
                    isPrime[coef * n - 1] = false;
                    primeFactors[coef * n - 1].push_back(n);
                }
            }
        }
        return primeFactors;
    }
    const auto primeFactors = makePrimeFactors();
}
class Solution {
public:
    static int findValidSplit(const std::vector<int>& nums) {
        std::unordered_set<int> overlapPrimeFactors{};
        std::unordered_map<int, int> rightPrimeFactorContribCounts{};
        for (const int num : nums) {
            for (const int factor : primeFactors[num - 1]) {
                ++rightPrimeFactorContribCounts[factor];
            }
        }
        for (int leftCount = 1; leftCount < nums.size(); ++leftCount) {
            for (const int prime : primeFactors[nums[leftCount - 1] - 1]) {
                auto it = rightPrimeFactorContribCounts.find(prime);
                if (it != rightPrimeFactorContribCounts.end()) {
                    if (it->second == 1) {
                        overlapPrimeFactors.erase(prime);
                        rightPrimeFactorContribCounts.erase(it);
                    } else {
                        overlapPrimeFactors.insert(prime);
                        --it->second;
                    }
                }
            }
            if (overlapPrimeFactors.empty()) {
                return leftCount - 1;
            }
        }
        return -1;
    }
};
