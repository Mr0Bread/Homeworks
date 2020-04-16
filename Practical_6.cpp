#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <map>

#define print std::cout
#define input std::cin
#define nl std::endl
#define str std::string

struct Country {
    str name;
    int size;

public:
    Country(str name, int size) {
        this->name = std::move(name);
        this->size = size;
    }
};

std::string askForFileName();

Country getCountryObject(const std::string& basicString);

int main() {
    std::map<str, int> sizes;
    std::vector<str> substrings;

    str fileName = askForFileName();
    str line;
    str smallestCountry;
    std::ifstream file;
    file.open(R"(C:\Users\zimni\CLionProjects\Homeworks\)" + fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            Country country = getCountryObject(line);
            sizes.insert(std::pair<str, int>(country.name, country.size));

            print << line << nl;

            substrings.clear();
        }

        print << "Smallest country is Vatican and it's size is equal to " <<  sizes.find("Vatican")->second << nl;

        while (true) {
            print << "Enter name of country to search for or enter 'exit' without quotes to exit from program\n> ";
            str name;
            input >> name;

            if (name == "exit") {
                break;
            }

            if (sizes.find(name) != sizes.end()) {
                print << "Size of " << name << " is equal to " << sizes.find(name)->second << nl;
            } else {
                print << "There is no such country in system!\n";
            }
        }

    } else {
        print << "Name of file is incorrect!\n";
    }

    file.close();
    return 0;
}

Country getCountryObject(const std::string& basicString) {
    int pos;
    int counter = 0;
    str name;
    for (char i : basicString) {
        if (isalpha(i)) {
            for (int c = counter;; c++) {
                if (!isalpha(basicString[c])) {
                    break;
                }
                name += basicString[c];
            }
            break;
        }
        counter++;
    }

    int size = std::stoi(basicString.substr(basicString.rfind(' '), basicString.rfind(' ')));
    return Country(name, size);
}

std::string askForFileName() {
    str fileName;
    print << "Enter name of file to open.\nHint: countriesSmall.txt\n> ";
    input >> fileName;
    return fileName;
}
