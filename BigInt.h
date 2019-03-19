#include<iostream>
#include "String.h"

class BigInt {
    friend int operator == (const BigInt&, const BigInt&);
    friend ostream& operator << (std::ostream&, const BigInt&);
    friend istream& operator >> (std::istream&, BigInt&);
    friend BigInt operator + (const BigInt&, const BigInt&);
    friend BigInt operator - (const BigInt&, const BigInt&);
    friend BigInt operator ++ (const BigInt& );
    friend BigInt operator -- (const BigInt& );
    friend int operator >= (const BigInt&, const BigInt&);
    friend int operator <= (const BigInt&, const BigInt&);
    friend int operator > (const BigInt&, const BigInt&);
    friend int operator < (const BigInt&, const BigInt&);

private:
    int* data;
    int length;
    int capacity;

public:
    BigInt();

    BigInt(const int&);

    BigInt(const String&);

    BigInt& operator = (const BigInt&);

    int sizeBI() const;
};