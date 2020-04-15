#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define print std::cout
#define input std::cin
#define nl std::endl
#define str std::string

std::string askForFileName();

int main() {
    std::vector<str> stringVector;

    str fileName = askForFileName();
    str line;
    str smallestCountry;
    std::ifstream file;
    file.open(R"(C:\Users\zimni\CLionProjects\Homeworks\)" + fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            stringVector.push_back(line);
            print << line << nl;
        }

        print << "Smallest country is " << stringVector.at(4) << nl;
        system("read");
    } else {
        print << "Name of file is incorrect!\n";
    }

    file.close();
    getchar();
    return 0;
}

std::string askForFileName() {
    str fileName;
    print << "Enter name of file to open.\nHint: countriesSmall.txt\n> ";
    input >> fileName;
    return fileName;
}
