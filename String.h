#include<iostream>

using namespace std;

int StrLen(char*);

class String {
    friend int operator == (const String&, const String&);
    friend ostream& operator << (std::ostream&, String&);
    friend istream& operator >> (std::istream&, String&);
    friend String operator + (String&, String&);

private:
    char* data;
    int capacity;
    int length;

public:
    String();

    String(const String &);

    String(char *);

    ~String();

    int size() const;

    String substring(int pos, int len);

    const char& operator[] (int) const;

    char& operator[](int);
};
