#include <iostream>
#include <string>
#include <algorithm>

#define print std::cout
#define nl std::endl
#define input std::cin
#define str std::string

char getOperator(std::string &basicString);

str getFirstNumStr(std::string &basicString, char oper);

str getSecondNumStr(std::string &basicString, char oper);

bool isNumStrValid(std::string &basicString, int *pInt);

int main() {
    print << "Calculator console application" << nl << nl;
    print << "Enter operation: |a + b|, |a - b|, |a * b|, |a / b|" << nl << "Enter \'exit\' to exit from program" << nl;

    bool run = true;

    while (run) {
        str operation;
        getline(input, operation);

        if (operation == "exit") {
            run = false;
            continue;
        }

        char oper = getOperator(operation);

        str numStr = getFirstNumStr(operation, oper);

        int firstNum;

        if (!isNumStrValid(numStr, &firstNum)) {
            print << "Invalid input" << nl << nl;
            continue;
        }

        numStr = getSecondNumStr(operation, oper);

        int secondNum;

        if (!isNumStrValid(numStr, &secondNum)) {
            print << "Invalid input" << nl << nl;
            continue;
        }

        double result;

        switch (oper) {
            case '+':
                result = firstNum + secondNum;
                break;
            case '-':
                result = firstNum - secondNum;
                break;
            case '*':
                result = firstNum * secondNum;
                break;
            case '/':
                result = (double) firstNum / secondNum;
                break;
            default:
                print << "SOMETHING WRONG!!!" << nl << nl;
                return 0;
        }

        print << "= " << result << nl << nl;
    }

    return 0;
}

bool isNumStrValid(std::string &basicString, int *pInt) {
    try {
        *pInt = std::stoi(basicString);
    } catch (...) {
        return false;
    }

    return true;
}

str getSecondNumStr(std::string &basicString, char oper) {
    basicString.erase(std::remove(basicString.begin(), basicString.end(), ' '), basicString.end());
    auto pos = basicString.find(oper);
    str numStr = basicString.substr(pos + 1);
    return numStr;
}

str getFirstNumStr(std::string &basicString, char oper) {
    auto pos = basicString.find(oper);
    str numStr = basicString.substr(0, pos);
    return numStr;
}

char getOperator(std::string &basicString) {
    char oper = 'a';

    for (char i : basicString) {
        if (i == '+' or i == '-' or i == '*' or i == '/') {
            oper = i;
        }
    }

    return oper;
}
