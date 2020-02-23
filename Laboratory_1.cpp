#include <iostream>
#include <string>
#include <vector>

#define print std::cout
#define str std::string
#define get std::cin
#define nl std::endl

std::string getConvertedString(const std::string &basicString);

int main() {
    print << "Enter string to print it out vice versa" << nl;
    str stringToConvert;
    std::getline(get, stringToConvert);

    str convertedString = getConvertedString(stringToConvert);
    print << "Converted string: " << convertedString << nl;

    system("read");
    return 0;
}

std::string getConvertedString(const std::string &basicString) {
    str convertedString;
    std::vector<str> stringVector;

    for (int i = 0, lastPos = 0; i < 1; ++i) {
        auto spacePos = basicString.find(' ', lastPos);

        if (spacePos != str::npos) {
            stringVector.push_back(basicString.substr(lastPos, spacePos - lastPos));
            lastPos = (int)spacePos + 1;
            i = -1;
        } else {
            try {
                stringVector.push_back(basicString.substr(lastPos, (basicString.length() - 1) - spacePos));
            } catch (...) {
                print << "exception handled!" << nl;
            }
        }
    }

    for (auto & j : stringVector) {
        auto charString = new char[j.length()];

        for (int i = 0; i < j.length(); ++i) {
            charString[i] = j[j.length() - i - 1];
        }

        convertedString.append(charString);

        if (j != stringVector.back()) {
            convertedString.append(" ");
        }

        delete[] charString;
    }

    return convertedString;
}
