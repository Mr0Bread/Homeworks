#include <iostream>
#include <fstream>
#include <string>

#define print std::cout
#define input std::cin
#define nl std::endl
#define str std::string

int main() {
    str fileName;
    str line;
    std::ifstream file;
    file.open("countriesSmall.txt");

    file.close();
    getchar();
    return 0;
}
