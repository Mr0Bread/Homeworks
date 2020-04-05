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
    std::fstream file;


    do {
        print << "Enter file name to open: ";
        input >> fileName;
        file.open(fileName, std::ios::in);

    } while (!file.is_open());

    while (std::getline(file, line)) {
        print << line << nl;
    }


    file.close();
    getchar();
    return 0;
}
