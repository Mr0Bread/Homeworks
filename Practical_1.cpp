#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#define print std::cout
#define tab "\t"
#define vtab "\n\n\n\n"

void printEmptyMatrix(std::string pString[6][6]);

void initBoolMatrix(bool pBoolean[6][6]);

int replaceRow(int rowIndex, int counter, std::string pString[6][6], bool pBoolean[6][6], std::string symbols[10]);

void printRow(int rowIndex, std::string pString[6][6]);

int main() {
    std::string matrix[6][6];

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            matrix[i][j] = ".";
        }
    }

    printEmptyMatrix(matrix);

    print << "Enter any key to continue...\n";
    getchar();
    print << std::string(50, '\n');

    std::string symbols[]{"/\\", "/_", "_", "_\\", "|", "X", "|", "|_", "_", "_|"};

    bool boolMatrix[6][6];

    initBoolMatrix(boolMatrix);

    int counter = 0;

    for (int rowIndex = 0; rowIndex < 6; ++rowIndex) {
        counter = replaceRow(rowIndex, counter, matrix, boolMatrix, symbols);
        printRow(rowIndex, matrix);
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    print << "Enter any key to exit...\n";

    getchar();

    return 0;
}

void printRow(int rowIndex, std::string pString[6][6]) {
    for (int i = 0; i < 6; ++i) {
        print << pString[rowIndex][i] << tab;
    }
    print << vtab;
}

int replaceRow(int rowIndex, int counter, std::string pString[6][6], bool pBoolean[6][6], std::string symbols[10]) {
    for (int i = 0; i < 6; ++i) {
        if (pBoolean[rowIndex][i]) {
            pString[rowIndex][i] = pString[rowIndex][i].replace(0, symbols[counter].length(),symbols[counter]);
            counter++;
        }
    }
    return counter;
}

void initBoolMatrix(bool pBoolean[6][6]) {
    for (int l = 0; l < 6; ++l) {
        for (int i = 0; i < 6; ++i) {
            pBoolean[l][i] = false;
        }
    }

    pBoolean[1][2] = true;
    pBoolean[2][1] = true;
    pBoolean[2][2] = true;
    pBoolean[2][3] = true;
    pBoolean[3][1] = true;
    pBoolean[3][2] = true;
    pBoolean[3][3] = true;
    pBoolean[4][1] = true;
    pBoolean[4][2] = true;
    pBoolean[4][3] = true;
}

void printEmptyMatrix(std::string pString[6][6]) {
    for (int n = 0; n < 6; ++n) {
        for (int i = 0; i < 6; ++i) {
            print << pString[n][i] << tab;
        }
        print << vtab;
    }
}
