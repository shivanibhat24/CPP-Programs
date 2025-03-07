class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool case1 = false, case2 = false;
        if ((long)length * (long)width * (long)height >= pow(10, 9)) {
            case1 = true;
        } else if (length >= pow(10, 4) || width >= pow(10, 4) ||
                   height >= pow(10, 4)) {
            case1 = true;
        }
        if (mass >= 100) {
            case2 = true;
        }
        if (case1 && case2) {
            return "Both";
        } else if (!case1 && !case2) {
            return "Neither";
        } else if (case1 == true && case2 == false) {
            return "Bulky";
        }
        return "Heavy";
    }
};
