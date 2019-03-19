#include "Modulo.h"
#include <iostream>


Modulo:: Modulo() {
    data = 0;
    length = 0;
}


Modulo:: Modulo(const BigInt& a) {
    BigInt d, c;
    d = a;
    c = 0;
    if (a <= n) {
        data = a;
        length = a.sizeBI();
    } else {
        while (d > n) {
            c = d;
            d = c - n;
        }
        data = d;
        length = d.sizeBI();
    }
}


Modulo& Modulo:: operator = (const Modulo& a){
    data = a.data;
    length = a.length;
}


int operator == (const Modulo& a, const Modulo& b){
    if (a.length == b.length) {
        if (a.data == b.data) {
            return 1;
        }
    } else return 0;
}


ostream& operator << (std::ostream& out, const Modulo& a) {
    std:: cout << a.data;
    return out;
}


istream& operator >> (std::istream& in, Modulo& a) {
    a.data = 0;
    BigInt b;
    std::cin >> b;
    a.data = b;
    a.length = b.sizeBI();
    return in;
}


Modulo operator + (const Modulo& a, const Modulo& b) {
    Modulo res;
    res.data = a.data + b.data;
    res.length = res.data.sizeBI();
    if (res.data <= res.n) {
        return res;
    } else {
        BigInt d, c;
        d = res.data;
        c = 0;
        while (d > res.n) {
            c = d;
            d = c - res.n;
        }
        res.data = d;
        res.length = d.sizeBI();
        return res;
    }
}


Modulo operator ++ (const Modulo& a) {
    Modulo res;
    BigInt b = 1;
    res.data = a.data + b;
    res.length = res.data.sizeBI();
    if (res.data <= res.n) {
        return res;
    } else {
        BigInt d, c;
        d = res.data;
        c = 0;
        while (d > res.n) {
            c = d;
            d = c - res.n;
        }
        res.data = d;
        res.length = d.sizeBI();
        return res;
    }
}


Modulo operator -- (const Modulo& a) {
    Modulo res;
    BigInt b = 1;
    res.data = a.data - b;
    res.length = res.data.sizeBI();
    if (res.data <= res.n) {
        return res;
    } else {
        BigInt d, c;
        d = res.data;
        c = 0;
        while (d > res.n) {
            c = d;
            d = c - res.n;
        }
        res.data = d;
        res.length = d.sizeBI();
        return res;
    }
}
