#include "BigInt.h"
#include <iostream>


BigInt:: BigInt() {
    data = nullptr;
    length = 0;
};


BigInt::BigInt(const int& a) {
    int b = a;
    int d = b;
    int k = 0;
    while (b != 0) {
        b /= 10;
        k++;
    }
    length = k;
    data = new int[k];
    int i = 0;
    while (d != 0) {
        int c = d % 10;
        d /= 10;
        data[i] = c;
        i++;
    }
};


BigInt:: BigInt(const String& str) {
    data = new int[str.size()];
    for (int i = 0; i < str.size(); i++) {
        data[i] = str[i];
    }
};


int BigInt:: sizeBI() const {
    return length;
}


BigInt& BigInt:: operator = (const BigInt& s) {
    delete[] data;
    data = new int [s.length];
    for (int i = 0; i < s.length; ++i){
        data[i] = s.data[i];
    }
    length = s.length;
    return *this;
};


std:: ostream& operator <<(std::ostream & out, const BigInt &s){
    for (int i = s.length - 1; i >= 0; --i) {
        std::cout<<s.data[i];
    }
    return out;
};


std::istream& operator >> (std::istream & in, BigInt &s){
    delete[] s.data;
    String str;
    std::cin>>str;
    int k = str.size();
    s.data = new int[k];
    for (int i = 0; i < k; ++i){
        char x = str[k - i - 1];
        int xx = x - '0';
        s.data[i] = xx;
    }
    s.length = k;
    str = "";
    return in;
}


int operator == (const BigInt& a, const BigInt& b) {
    if (a.length != b.length) {
        return 0;
    }
    else {
        for(int i = 0; i < a.length; i++) {
            if (a.data[i] != b.data[i]) {
                return 0;
            }
        }
        return 1;
    }
}


BigInt operator + (const BigInt& a, const BigInt& b) {
    BigInt res;
    int d = 0;
    if (a.length == b.length) {
        res.data = new int[a.length];
        res.length = a.length;
        for (int i = 0; i < a.length; i++) {
            if ((a.data[i] + b.data[i] + d) >= 10) {
                int x = a.data[i] + b.data[i] + d;
                x %= 10;
                res.data[i] = x;
                d = 1;
            } else {
                res.data[i] = a.data[i] + b.data[i] + d;
                d = 0;
            }
        }
        if (d == 1) {
            BigInt rest;
            rest.data = new int[a.length + 1];
            rest.length = a.length + 1;
            for (int i = 0; i <= a.length; i++) {
                if (i < a.length) {
                    rest.data[i] = res.data[i];
                } else rest.data[i] = 1;
            }
            return rest;
        } else return res;
    } else if (a.length > b.length) {
        res.data = new int[a.length];
        res.length = a.length;
        for (int i = 0; i < b.length; i++) {
            if ((a.data[i] + b.data[i] + d) >= 10) {
                int x = a.data[i] + b.data[i] + d;
                x %= 10;
                res.data[i] = x;
                d = 1;
            } else {
                res.data[i] = a.data[i] + b.data[i] + d;
                d = 0;
            }
        }
        if (d == 1) {
            for (int i = b.length; i < a.length; i++) {
                if ((a.data[i] + d) >= 10) {
                    res.data[i] = 0;
                    d = 1;
                } else {
                    res.data[i] = a.data[i] + d;
                    d = 0;
                }
            }
        } else for (int i = b.length; i < a.length; i++) {
            res.data[i] = a.data[i];
        }
        if (d == 1) {
            BigInt rest;
            rest.data = new int[a.length + 1];
            rest.length = a.length + 1;
            for (int i = 0; i <= a.length; i++) {
                if (i < a.length) {
                    rest.data[i] = res.data[i];
                } else rest.data[i] = 1;
            }
            return rest;
        } else return res;
    } else {
        res.data = new int[b.length];
        res.length = b.length;
        for (int i = 0; i < a.length; i++) {
            if ((a.data[i] + b.data[i] + d) >= 10) {
                int x = a.data[i] + b.data[i] + d;
                x %= 10;
                res.data[i] = x;
                d = 1;
            } else {
                res.data[i] = a.data[i] + b.data[i] + d;
                d = 0;
            }
        }
        if (d == 1) {
            for (int i = a.length; i < b.length; i++) {
                if ((b.data[i] + d) >= 10) {
                    res.data[i] = 0;
                    d = 1;
                } else {
                    res.data[i] = b.data[i] + d;
                    d = 0;
                }
            }
        }
        if (d == 1) {
            BigInt rest;
            rest.data = new int[b.length + 1];
            rest.length = b.length + 1;
            for (int i = 0; i <= b.length; i++) {
                if (i < b.length) {
                    rest.data[i] = res.data[i];
                } else rest.data[i] = 1;
            }
            return rest;
        } else return res;
    }
}


BigInt operator ++ (const BigInt& a) {
    BigInt b = 1;
    return a + b;
}


BigInt operator -- (const BigInt& a) {}


int operator >= (const BigInt& a, const BigInt& b) {
    if (a.length > b.length) {
        return 1;
    } else  if (a.length < b.length) {
        return 0;
    } else {
        int flag = 1;
        for (int i = a.length - 1;  i >= 0; --i) {
            if (a.data[i] > b.data[i]) {
                flag = 1;
                break;
            } else if (a.data[i] == b.data[i]) {
                flag = 1;
                continue;
            } else if (a.data[i] < b.data[i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            return 1;
        } else return 0;
    }
}


int operator <= (const BigInt& a, const BigInt& b) {
    if (b.length > a.length) {
        return 1;
    } else  if (b.length < a.length) {
        return 0;
    } else {
        int flag = 1;
        for (int i = b.length - 1;  i >= 0; --i) {
            if (b.data[i] > a.data[i]) {
                flag = 1;
                break;
            } else if (b.data[i] == a.data[i]) {
                flag = 1;
                continue;
            } else if (b.data[i] < a.data[i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            return 1;
        } else return 0;
    }
}


int operator > (const BigInt& a, const BigInt& b) {
    if (a.length > b.length) {
        return 1;
    } else  if (a.length < b.length) {
        return 0;
    } else {
        int flag = 1;
        for (int i = a.length - 1;  i >= 0; --i) {
            if (a.data[i] > b.data[i]) {
                flag = 1;
                break;
            } else if (a.data[i] == b.data[i]) {
                flag = 1;
                if (i == 0) {
                    if (a.data[i] > b.data[i]) {
                        flag = 1;
                    } else flag = 0;
                }
            } else if (a.data[i] < b.data[i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            return 1;
        } else return 0;
    }
}


int operator < (const BigInt& a, const BigInt& b) {
    if (b.length > a.length) {
        return 1;
    } else  if (b.length < a.length) {
        return 0;
    } else {
        int flag = 1;
        for (int i = b.length - 1;  i >= 0; --i) {
            if (b.data[i] > a.data[i]) {
                flag = 1;
                break;
            } else if (b.data[i] == a.data[i]) {
                flag = 1;
                if (i == 0) {
                    if (b.data[i] > a.data[i]) {
                        flag = 1;
                    } else flag = 0;
                }
            } else if (b.data[i] < a.data[i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            return 1;
        } else return 0;
    }
}

BigInt operator - (const BigInt& a, const BigInt& b) {
    BigInt res;
    res.data = new int[a.length];
    res.length = a.length;
    int d = 0;
    for (int i = 0; i < a.length; i++) {
        if (i >= b.length) {
            if (d == 0) {
                for (int j = 0; j < a.length; j++) {
                    res.data[j] = 0;
                }
            } else {
                if (a.data[i] == 0) {
                    res.data[i] = 9;
                    d = 1;
                } else {
                    res.data[i] = a.data[i] - 1;
                    d = 0;
                }
            }
        } else {
            if (d == 0) {
                if (a.data[i] - b.data[i] >= 0) {
                    res.data[i] = a.data[i] - b.data[i];
                } else {
                    res.data[i] = a.data[i] + 10 - b.data[i];
                    d = 1;
                }
            }
            else {
                if (a.data[i] == 0) {
                    res.data[i] = 9 - b.data[i];
                    d = 1;
                } else if (a.data[i] - 1 != 0) {
                    a.data[i] = a.data[i] - 1;
                    d = 0;
                    if (a.data[i] - b.data[i] >= 0) {
                        res.data[i] = a.data[i] - b.data[i];
                    } else {
                        res.data[i] = a.data[i] + 10 - b.data[i];
                        d = 1;
                    }
                } else {
                    res.data[i] = 10 - b.data[i];
                    d = 1;
                }
            }
        }
    }
    if (res.data[res.length - 1] == 0) {
        int i = res.length - 1;
        while (res.data[i] == 0) {
            i--;
        }
        BigInt rest;
        rest.data = new int[i + 1];
        rest.length = i + 1;
        for (int j = 0; j <= i; j++) {
            rest.data[j] = res.data[j];
        }
        return rest;
    } else return res;
}
