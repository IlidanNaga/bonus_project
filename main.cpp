#include <iostream>
#include <string.h>

#include "mystr.h"



int main() {

    mystr test;
    std::cout << "Please, input text:" << std::endl;
    std::cin >> test;

    test += "abcd";
    std::cout << "Summed with abcd: " << test << std::endl;

    test = test + test;

    std::cout << "Summed with itself by + : " << test << std::endl;

    test += test;

    std::cout << "Summed with itself by += : " << test << std::endl;

    std::cout << (test == test) << std:: endl;

    return 0;
}