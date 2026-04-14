class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        if (queries.empty()) {
            throw invalid_argument("queries must contain at least one query.");
        }
        for (const auto& singleQuery : queries) {
            if (singleQuery.size() != 2 || singleQuery[0] < 1 || singleQuery[1] < 1) {
                throw invalid_argument("Each query must be [n, k] with n >= 1 and k >= 1.");
            }
        }
        static constexpr long long MODULUS = 1'000'000'007LL;
        static constexpr int MAX_VALUE = 10'000;
        static constexpr int MAX_EXPONENT = 13;
        static constexpr int FACTORIAL_LIMIT = MAX_VALUE + MAX_EXPONENT;
        static vector<long long> factorialTable;
        static vector<long long> inverseFactorialTable;
        static vector<int> smallestPrimeFactor;
        static bool tablesInitialized = false;
        if (!tablesInitialized) {
            factorialTable.assign(FACTORIAL_LIMIT + 1, 1LL);
            for (int value = 1; value <= FACTORIAL_LIMIT; ++value) {
                factorialTable[value] = factorialTable[value - 1] * value % MODULUS;
            }
            inverseFactorialTable.assign(FACTORIAL_LIMIT + 1, 1LL);
            long long base = factorialTable[FACTORIAL_LIMIT];
            long long exponent = MODULUS - 2;
            long long modularInverse = 1LL;
            while (exponent > 0) {
                if (exponent & 1LL) {
                    modularInverse = modularInverse * base % MODULUS;
                }
                base = base * base % MODULUS;
                exponent >>= 1;
            }
            inverseFactorialTable[FACTORIAL_LIMIT] = modularInverse;
            for (int value = FACTORIAL_LIMIT - 1; value >= 0; --value) {
                inverseFactorialTable[value] =
                    inverseFactorialTable[value + 1] * (value + 1) % MODULUS;
            }
            smallestPrimeFactor.assign(MAX_VALUE + 1, 0);
            for (int candidate = 2; candidate <= MAX_VALUE; ++candidate) {
                if (smallestPrimeFactor[candidate] == 0) {
                    for (int multiple = candidate; multiple <= MAX_VALUE; multiple += candidate) {
                        if (smallestPrimeFactor[multiple] == 0) {
                            smallestPrimeFactor[multiple] = candidate;
                        }
                    }
                }
            }

            tablesInitialized = true;
        }
        auto binomialModular = [&](int upper, int lower) -> long long {
            if (lower < 0 || lower > upper) {
                return 0LL;
            }
            return factorialTable[upper] * inverseFactorialTable[lower] % MODULUS
                   * inverseFactorialTable[upper - lower] % MODULUS;
        };
        vector<int> answers;
        answers.reserve(queries.size());
        for (const auto& singleQuery : queries) {
            int slotCount = singleQuery[0];
            int productTarget = singleQuery[1];
            long long wayCount = 1LL;
            int remaining = productTarget;
            while (remaining > 1) {
                int primeFactor = smallestPrimeFactor[remaining];
                int exponentCount = 0;
                while (remaining % primeFactor == 0) {
                    remaining /= primeFactor;
                    ++exponentCount;
                }
                wayCount = wayCount *
                           binomialModular(exponentCount + slotCount - 1, exponentCount) %
                           MODULUS;
            }
            answers.push_back(static_cast<int>(wayCount));
        }
        return answers;
    }
};
