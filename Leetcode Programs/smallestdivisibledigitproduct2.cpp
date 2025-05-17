int num_size, i, j;
int num2, num3, num5, num7;
char a, ri, len, need2, need3, ri2, ri3, ri5, ri7;
bool need_increase;

#define LIKELY(x)    (__builtin_expect(!!(x), 1))
#define UNLIKELY(x)  (__builtin_expect(!!(x), 0))

class Solution {
public:
    string smallestNumber(string num, long long t) {
        num_size = num.size();
        if (UNLIKELY(t == 1)) {
            for (i = 0; i < num.size(); ++i) {
                if (UNLIKELY(num[i] == '0')) {
                    break;
                }
            }

            for (; i < num_size; ++i) {
                num[i] = '1';
            }

            return num;
        }

        num2 = __builtin_ctzll(t);
        t >>= num2;

        num3 = 0, num5 = 0, num7 = 0;
        while (t % 3 == 0) {
            ++num3;
            t /= 3;
        }
        while (t % 5 == 0) {
            ++num5;
            t /= 5;
        }
        while (t % 7 == 0) {
            ++num7;
            t /= 7;
        }

        if (UNLIKELY(t != 1)) {
            return "-1";
        }

        for (i = 0; i < num_size; ++i) {
            if (UNLIKELY(num[i] == '0')) break;
            switch(num[i] - '0') {
                case 9: num3 -= 2; break;
                case 8: num2 -= 3; break;
                case 7: --num7; break;
                case 6: --num2; --num3; break;
                case 5: --num5; break;
                case 4: num2 -= 2; break;
                case 3: --num3; break;
                case 2: --num2; break;
                default: break;
            }
        }

        for (; i < num_size; ++i) {
            num[i] = '1';
        }

        if (num2 < 1 && num3 < 1 && num5 < 1 && num7 < 1) {
            return num;
        }
        
        need_increase = true;
        for (i = num_size - 1; i >= 0; --i) {
            a = num[i] - '0';
            switch(a) {
                case 9: num3 += 2; break;
                case 8: num2 += 3; break;
                case 7: ++num7; break;
                case 6: ++num2; ++num3; break;
                case 5: ++num5; break;
                case 4: num2 += 2; break;
                case 3: ++num3; break;
                case 2: ++num2; break;
                default: break;
            }

            need2 = max(num2, 0);
            need3 = max(num3, 0);
            len = need2 / 3 + need3 / 2 + max(num5, 0) + max(num7, 0);
            need2 = need2 % 3;
            need3 = need3 % 2;
            len += (need2 + need3) / 2 + (need2 + need3) % 2;

            if (UNLIKELY(len <= num_size - i)) {
                for (ri = a + need_increase; ri < 10; ++ri) {
                    ri2 = 0, ri3 = 0, ri5 = 0, ri7 = 0;
                    switch(ri) {
                        case 9: ri3 += 2; break;
                        case 8: ri2 += 3; break;
                        case 7: ++ri7; break;
                        case 6: ++ri2; ++ri3; break;
                        case 5: ++ri5; break;
                        case 4: ri2 += 2; break;
                        case 3: ++ri3; break;
                        case 2: ++ri2; break;
                        default: break;
                    }

                    need2 = max(num2 - ri2, 0);
                    need3 = max(num3 - ri3, 0);
                    len = need2 / 3 + need3 / 2 + max(num5 - ri5, 0) + max(num7 - ri7, 0);
                    need2 = need2 % 3;
                    need3 = need3 % 2;
                    len += (need2 + need3) / 2 + (need2 + need3) % 2;

                    if (LIKELY(len < num_size - i)) {
                        num[i] = ri + '0';
                        num2 -= ri2;
                        num3 -= ri3;
                        num5 -= ri5;
                        num7 -= ri7;
                        for (j = num_size - 1; j > i; --j) {
                            if (num3 > 1) {
                                num[j] = '9';
                                num3 -= 2;
                            } else if (num2 > 2) {
                                num[j] = '8';
                                num2 -= 3;
                            } else if (num7 > 0) {
                                num[j] = '7';
                                --num7;
                            } else if (num2 > 0 && num3 > 0) {
                                num[j] = '6';
                                --num2, --num3;
                            } else if (num5 > 0) {
                                num[j] = '5';
                                --num5;
                            } else if (num2 > 1) {
                                num[j] = '4';
                                num2 -= 2;
                            } else if (num3 > 0) {
                                num[j] = '3';
                                --num2;
                            } else if (num2 > 0) {
                                num[j] = '2';
                                --num2;
                            } else {
                                num[j] = '1';
                            }
                        }
                        return num;
                    }
                }

                num[i] = '1';
                need_increase = false;

                for (j = i - 1; LIKELY(j >= 0); --j) {
                    a = num[j] - '0';
                    if (UNLIKELY(a != 9)) {
                        switch (a) {
                            case 8: num2 += 3, num3 -= 2; break;
                            case 7: ++num7, num2 -= 3; break;
                            case 6: ++num2, ++num3, --num7; break;
                            case 5: ++num5, --num2, --num3; break;
                            case 4: num2 += 2, --num5; break;
                            case 3: ++num3, num2 -= 2; break;
                            case 2: ++num2, --num3; break;
                            default: --num2; break;
                        }
                        ++num[j];
                        break;
                    }
                    num[j] = '1';
                    num3 += 2;
                }
                if (j == -1) {
                    num.insert(num.begin(), '1');
                    ++num_size;
                    break;
                }
            }
        }

        if (need_increase) {
            num.insert(num.begin(), '1');
            ++num_size;
        }

        i = num_size - 1;
        while (num2 > 0 || num3 > 0 || num5 > 0 || num7 > 0) {
            if (num3 > 1) {
                a = '9';
                num3 -= 2;
            } else if (num2 > 2) {
                a = '8';
                num2 -= 3;
            } else if (num7 > 0) {
                a = '7';
                --num7;
            } else if (num2 > 0 && num3 > 0) {
                a = '6';
                --num2, --num3;
            } else if (num5 > 0) {
                a = '5';
                --num5;
            } else if (num2 > 1) {
                a = '4';
                num2 -= 2;
            } else if (num3 > 0) {
                a = '3';
                --num3;
            } else if (num2 > 0) {
                a = '2';
                --num2;
            }
            if (LIKELY(i > -1)) {
                num[i--] = a;
            } else {
                num.reserve(21);
                num.insert(num.begin(), a);
            }
        }
        return num;
    }
};
