class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);

        // Multiply each digit from num1 and num2
        for (int i = m - 1; i >= 0; i--) {
            int d1 = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
                int d2 = num2[j] - '0';
                int mul = d1 * d2 + result[i + j + 1];

                result[i + j + 1] = mul % 10;
                result[i + j] += mul / 10;
            }
        }

        // Convert result vector to a string
        string product;
        bool leadingZero = true;

        for (int num : result) {
            if (num != 0) leadingZero = false;
            if (!leadingZero) product += (num + '0');
        }

        return product.empty() ? "0" : product;
    }
};
