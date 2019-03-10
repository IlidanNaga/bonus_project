#pragma once

#include <iostream>
#include <string.h>

class mystr {
private:
    char *p;
    int len;
public:
    static int objects;
    static int size;

    int getlen() const;

    char* getstring() const;

    mystr();
    mystr(const int);
    mystr(const mystr&);
    mystr(const char *);
    mystr(char, int);

    ~mystr();

    operator int();

    mystr& operator+=(const mystr&);
    mystr& operator+=(const char *s);

    mystr& operator=(const mystr &);
    mystr& operator=(const char *);

    mystr operator+(mystr&);

    friend std::ostream& operator <<(std::ostream &out, const mystr &res);
    friend std::istream& operator >>(std::istream &, mystr &);

    char& operator[](int) const;

    bool operator==(const mystr &);

};

bool operator>(const mystr &,const mystr &);
bool operator<(const mystr &,const mystr &);
