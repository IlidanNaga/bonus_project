#include "mystr.h"

int mystr::objects = 0;
int mystr::size = 0;

//return len of line
int mystr::getlen() const {
    return this->len;
}
//return line itself
char* mystr::getstring() const {
    return this->p;
}
//constructor: create blank line
mystr::mystr() {
    this->p = nullptr;
    this->len = 0;
    mystr::objects ++;
}
//constructor: create line from int
mystr::mystr(int a) {
    this->len = sizeof(int);
    mystr::size += this->len;
    mystr::objects ++;

    this->p = new char[sizeof(int)];
    sprintf(this->p, "%d", a);
}
//constructor: create line from another line
mystr::mystr(const mystr &s) {
    this->len = s.len;
    this->p = new char[this->len + 1];

    mystr::objects ++;
    mystr::size += this->len;
    strcpy(this->p, s.p);
}
//constructor: create line from char*
mystr::mystr(const char *other) {
    this->len = strlen(other);
    this->p = new char[this->len + 1];
    for (int i = 0; i <= this->len; i++)
        p[i] = other[i];
    mystr::objects++;
    mystr::size += this->len;
}
//constructor: create line of same
mystr::mystr(char c, int n) {
    this->len = n;
    this->p = new char[this->len];

    mystr::objects ++;
    mystr::size += this->len;

    for (int i  = 0; i < n; i++) {
        this->p[i] = c;
    }
}
//destructor
mystr::~mystr() {
    //std::cout << "deleted mystr object with data " << this->p << std::endl;
    delete this->p;
    mystr::size -= this->len;
    mystr::objects --;

    //std::cout << "currently " << mystr::objects << " objects of size " << mystr::size << std::endl;

    if (!mystr::objects) {
        std::cout << "No more mystr objects (size = " << size << ")" << std::endl;

    }
}
// (int) for class member
mystr::operator int() {
    return atoi(p);
}
//operator = for string
mystr& mystr::operator=(const char *s) {

    if (this->p == s)
        return *this;

    delete this->p;

    mystr::size += strlen(s) - this->len;

    this->len = strlen(s);
    this->p = new char[this->len + 1];

    strcpy(this->p, s);

    return *this;


}
//operator = for class member
mystr& mystr::operator=(const mystr &s) {
    if (*this == s) {
        return *this;
    }

    mystr::size += s.getlen() - this->len;
    this->len = s.getlen();

    delete(this->p);
    this->p = new char[this->len + 1];

    for (int i = 0; i <= this->len; i++) {
        this->p[i] = s[i];
    }
    return *this;
}
//operator += for class member
mystr& mystr::operator+=(const mystr &s) {
    char *new_str = new char[this->len + s.getlen() + 1];
    strcpy(new_str, this->p);
    strcat(new_str, s.p);

    mystr::size += s.getlen() + 1;

    delete this->p;

    this->len += s.getlen() + 1;
    this->p = new char[this->len];

    strcpy(this->p, new_str);

    return *this;

}
//operator += for *char
mystr& mystr::operator+=(const char *s) {
    char *hold = new char[this->len + strlen(s)];
    strcpy(hold, this->p);
    strcat(hold, s);

    delete(this->p);

    this->p = new char[this->len + strlen(s)];
    strcpy(this->p, hold);

    this->len += strlen(s);
    mystr::size += strlen(s);

    return *this;

}
//operator + for class member
mystr mystr::operator+(mystr &s) {
    char *new_str = new char[this->len + s.getlen()];

    strcpy(new_str, this->p);
    strcat(new_str, s.p);

    return mystr(new_str);
}
//operator <<
std::ostream& operator<<(std::ostream &out, const mystr &rec) {
    for (int i = 0; i < rec.len; i++)
        out << rec.p[i];
    return out;
}
//operator >>
std::istream& operator>>(std::istream &in, mystr &rec) {
    char *hold = new char[4096];
    in >> hold;
    rec = hold;
    return in;
}
//operator []
char& mystr::operator[](int index) const {
    if (index < 0 || index >= this->len)
        return this->p[this->len];
    return this->p[index];
}
//boolean operators
//==
bool mystr::operator==(const mystr &compare) {
    try {
        if (!strcmp(this->p, compare.p))
            return true;
        return false;
    }
    catch (...) {
        if (this->len == compare.len)
            return true;
        return false;
    }
}
//>
bool operator>(const mystr &left,const mystr &right) {
    try {
        if (strcmp(left.getstring(), right.getstring()) < 0)
            return true;
        return false;
    }
    catch (...) {
        if (left.getlen() > right.getlen())
            return true;
        return false;
    }
}
//<
bool operator<(const mystr &left, const mystr &right) {
    try {
        if (strcmp(left.getstring(), right.getstring()) > 0)
            return true;
        return false;
    }
    catch (...) {
        if (left.getlen() < right.getlen())
            return true;
        return false;
    }
}