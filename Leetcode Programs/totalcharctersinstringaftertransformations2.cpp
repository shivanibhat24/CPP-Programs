
class Solution {
    public:
     static constexpr int MOD = 1'000'000'007;
     static constexpr int ALPHABET_SIZE = 26;
 
     using Matrix = array<array<size_t, ALPHABET_SIZE>, ALPHABET_SIZE>;
 
     static int lengthAfterTransformations(const string& s, const int t, const vector<int>& nums) {
         array<int, ALPHABET_SIZE> x{};
         for (const char c : s) x[c - 'a']++;
 
         if (t < 500) {
             for (size_t i = 0; i < t; ++i) x = transform(x, nums);
             return accumulate(x.begin(), x.end(), 0, [](const size_t a, const size_t b) { return (a + b) % MOD; });
         }
 
         Matrix a{};
         for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
             for (size_t k = 0; k < nums[i]; ++k) {
                 a[(i + 1 + k) % ALPHABET_SIZE][i] = 1;
             }
         }
 
         const Matrix b = matrixPower(a, t);
         array<size_t, ALPHABET_SIZE> y = {0};
         for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
             for (size_t j = 0; j < ALPHABET_SIZE; ++j) {
                 y[i] = (y[i] + b[i][j] * x[j]) % MOD;
             }
         }
 
         return accumulate(y.begin(), y.end(), 0, [](const size_t acc, const size_t val) { return (acc + val) % MOD; });
     }
 
    private:
     static array<int, ALPHABET_SIZE> transform(const array<int, ALPHABET_SIZE>& x, const vector<int>& nums) {
         array<int, ALPHABET_SIZE> y = {};
 
         for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
             for (size_t k = 0; k < nums[i]; ++k) {
                 y[(i + 1 + k) % ALPHABET_SIZE] = (y[(i + 1 + k) % ALPHABET_SIZE] + x[i]) % MOD;
             }
         }
 
         return y;
     }
 
     static Matrix matrixMultiply(const Matrix& a, const Matrix& b) {
         Matrix c{};
 
         for (size_t i = 0; i < ALPHABET_SIZE; ++i) {
             for (size_t j = 0; j < ALPHABET_SIZE; ++j) {
                 for (size_t k = 0; k < ALPHABET_SIZE; ++k) {
                     c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                 }
             }
         }
 
         return c;
     }
 
     static Matrix matrixPower(const Matrix& a, int t) {
         Matrix base{a};
         Matrix result{};
         for (size_t i = 0; i < ALPHABET_SIZE; ++i) result[i][i] = 1;
 
         while (t > 0) {
             if (t % 2 == 1) result = matrixMultiply(result, base);
             base = matrixMultiply(base, base);
             t /= 2;
         }
 
         return result;
     }
 };  

    
