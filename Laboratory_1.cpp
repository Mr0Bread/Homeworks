#include <iostream>
#include <string>

std::string getConvertedWord(std::string &tempString) {
    int lengthInit = (int)tempString.length();
    char* charString = new char[lengthInit];

    for (int startIndex = 0, endIndex = lengthInit - 1; startIndex < lengthInit; ++startIndex, endIndex--) {
        charString[startIndex] = tempString[endIndex];
    }


    std::string convertedWord = charString;
    int lengthAfter = (int)convertedWord.length();

    if (lengthAfter > lengthInit) {
        auto diff = lengthAfter - lengthInit;

        for (int i = 0; i < diff; i ++) {
            convertedWord.pop_back();
        }
    }

    delete[] charString;
    return convertedWord;
}

int main() {
    std::cout << "Enter string to convert" << std::endl;
    std::string toConvert;
    std::string tempString;
    getline(std::cin, toConvert);

    auto spacePos = toConvert.find(' ');
    int lastPos = 0;

    for (; spacePos != std::string::npos;) {
        tempString = toConvert.substr(lastPos, spacePos - lastPos);
        std::string convertedWord = getConvertedWord(tempString);
        toConvert.replace(lastPos, spacePos - lastPos, convertedWord);
        lastPos = (int)spacePos + 1;
        spacePos = toConvert.find(' ', lastPos);
    }

    tempString = toConvert.substr(lastPos, toConvert.length() - lastPos);
    std::string convertedWord = getConvertedWord(tempString);
    toConvert.replace(lastPos, spacePos - lastPos, convertedWord);

    std::cout << "Converted string: " + toConvert << std::endl;

    getchar();
    return 0;
}