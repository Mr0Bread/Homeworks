#include <iostream>
#include <string>

#define print std::cout
#define newline std::endl
#define get std::cin


int main() {
    print << "Enter first string\n";
    std::string string1;
    get >> string1;

    print << "Enter second string\n";
    std::string string2;
    get >> string2;

    char* charString = new char[string2.length()];

    for (int i = 0; i < string2.length(); i++) {
        charString[i] = string2[i];
    }

    print << "string.compare(string2) result is ";
    print << string1.compare(string2) << newline;

    print << "string1.compare(0, 4, string2) result is ";
    print << string1.compare(0, 4, string2) << newline;

    print << "string1.compare(0, 4, string2, 0, 4) result is ";
    print << string1.compare(0, 4, string2, 0, 4) << newline;

    print << "string1.compare(charString) result is ";
    print << string1.compare(charString) << newline;

    print << "string1.compare(1, 5, charString) result is ";
    print << string1.compare(1, 5, charString) << newline;

    std::cout << "string1.compare(0, 4, charString, 4) result is ";
    std::cout << string1.compare(0, 4, charString, 4) << std::endl;

    system("read");
    return 0;
}
