#include "String.h"
#include <iostream>

String:: String() {
    length = 0;
    capacity = 0;
    data = nullptr;
};

String:: ~String() {
    delete[] data;
    length = 0;
    capacity = 0;
};

int String:: size() const {
    return length;
}

String:: String(char* str) {
    int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    data = new char [size];
    for (int i = 0; i < size; i++) {
        data[i] = str[i];
    }
    length = size;
    capacity = size * 2;
}

String:: String(const String &str) {
    data = new char [str.size()];
    for (int i = 0; i < str.size(); i++) {
        data[i] = str[i];
    }
    length = str.size();
    capacity = length * 2;
}


std:: ostream& operator << (std::ostream & out, String &str){
    for(int i = 0; i < str.length; i++) {
        cout << str.data[i];
    }
    return out;
}

std::istream& operator >> (std::istream& in, String &str){
    delete [] str.data;
    auto s = new char[1000];
    std::cin >> s;
    int i = 0;
    int k = 0;
    while (s[i] != '\0') {
        k++;
        i++;
    }
    str.data = new char[k];
    for(int i = 0; i < k; i++) {
        str.data[i] = s[i];
    }
    str.length = k;
    str.capacity = k * 2;
    delete [] s;
    return in;
}

int operator == (const String &left, const String &right) {
    if (left.length != right.length) {
        return 0;
    }
    else {
        for(int i = 0; i < left.length; i++) {
            if (left.data[i] != right.data[i]) {
                return 0;
            }
        }
        return 1;
    }
};

String operator + (String& left, String& right) {
    String res;
    res.data = new char [left.length + right.length];
    res.length = left.length + right.length;
    res.capacity = res.length * 2;
    for (int i = 0; i < left.length; ++i){
        res.data[i] = left.data[i];
    }
    for (int i = 0; i < right.length; ++i){
        res.data[i + left.length] = right.data[i];
    }
    return res;
}

const char& String::operator[](int i) const {
        return (i >= 0 && i < StrLen(this->data)) ? this->data[i] : 0;
}

int StrLen(char* _str)
{
    int size = 0;

    for (; _str[size] != 0; size++);

    return size;
}


char& String::operator[](int i)
{
    static char s;
    return (i >= 0 && i < StrLen(this->data)) ? this->data[i] : s;
}

String String:: substring( int pos, int len){
    String res;
    res.data = new char[len];
    for(int i = 0; i < len; i++) {
        res.data[i] = data[pos+i];
    }
    res.length = len;
    res.capacity = len * 2;
    return res;
}