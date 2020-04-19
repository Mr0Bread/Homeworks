#include <iostream>
#include <string>

#define print std::cout
#define input std::cin
#define nl std::endl
#define str std::string

struct Letter {
    char character;
    str dots;
};

void prepareArrayOfStructs(Letter pLetter[26]);

void printArrayOfStructures(Letter pLetter[26]);

void printConvertedInput(const std::string& basicString, Letter pLetter[26]);

void printConvertedLetter(char i, Letter *pLetter);

std::string capitalizeInput(const std::string& basicString);

int main() {
    Letter letters[26];
    prepareArrayOfStructs(letters);

    print << "Enter string to convert to Tap Code\n> ";
    str inputToConvert;
    getline(input, inputToConvert);
    inputToConvert = capitalizeInput(inputToConvert);
    printConvertedInput(inputToConvert, letters);

    return 0;
}

std::string capitalizeInput(const std::string& basicString) {
    str capitalized;

    for (char i : basicString) {
        if (isalpha(i)) {
            capitalized += toupper(i);
        } else if (i == ' ') {
            capitalized += ' ';
        }
    }

    return capitalized;
}

void printConvertedInput(const std::string& basicString, Letter pLetter[26]) {
    for (char i : basicString) {
        if (isalpha(i)) {
            printConvertedLetter(i, pLetter);
            print << "  ";
        } else if (i == ' ') {
            print << "/  ";
        }
    }
}

void printConvertedLetter(char i, Letter *pLetter) {
    int index = (int) i - 65;
    print << pLetter[index].dots;
}

void printArrayOfStructures(Letter pLetter[26]) {
    for (int i = 0; i < 26; i++) {
        print << pLetter[i].character << " : " << pLetter[i].dots << nl;
    }
}

void prepareArrayOfStructs(Letter pLetter[26]) {
    for (int index = 0, code = 65, row = 1, column = 1;
         index < 26;
         index++, code++, column++) {

        char character = (char) code;
        Letter letter;
        letter.character = character;

        str dots;
        int rowDotsCount;
        int colDotsCount;

        if (character == 'K') {
            column -= 1;

            rowDotsCount = 1;
            colDotsCount = 3;
        } else {
            rowDotsCount = row;
            colDotsCount = column;
        }

        for (int i = 0; i < rowDotsCount; i++) {
            dots += ".";
        }

        dots += " ";

        for (int i = 0; i < colDotsCount; i++) {
            dots += ".";
        }

        letter.dots = dots;

        pLetter[index] = letter;

        if (column == 5) {
            column = 0;
            row++;
        }
    }
}

