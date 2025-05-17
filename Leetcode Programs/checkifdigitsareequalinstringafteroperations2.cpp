class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        int m = n - 2;
        int m_digits[10], m_size = 0;
        int temp = m;
        if (temp == 0) {
            m_digits[m_size++] = 0;
        } else {
            while (temp > 0) {
                m_digits[m_size++] = temp % 5;
                temp /= 5;
            }
        }
        const int small[5][5] = {{1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 2, 1, 0, 0}, {1, 3, 3, 1, 0}, {1, 4, 1, 4, 1}};        
        int diff = 0;
        for (int j = 0; j <= m; j++) {
            int res5 = 1;
            int x = j;
            for (int i = 0; i < m_size; i++) {
                int d = x % 5;
                x /= 5;
                int a = m_digits[i];
                if (d > a) { 
                    res5 = 0;
                    break;
                }
                res5 = (res5 * small[a][d]) % 5;
            }
            int c2 = ((m & j) == j) ? 1 : 0;
            int coeff = ((res5 & 1) == c2) ? res5 : res5 + 5;
            int delta = (s[j] - '0') - (s[j + 1] - '0');
            diff = (diff + coeff * delta) % 10;
            if (diff < 0)
                diff += 10;
        }
        return diff == 0;
    }
};
