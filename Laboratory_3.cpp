#include <iostream>
#include <string>

#define print std::cout
#define input std::cin
#define nl std::endl
#define str std::string

#define MAX_INPUT 100 // These constants hold high and low integer numbers,
#define MIN_INPUT 1
#define ARRAY_SIZE 4   // and the array size declarator.

str convert(int digit, str low, str mid, str high) {

    if (digit == 1) {
        return low;
    }
    if (digit == 2) {
        return low + low;
    }
    if (digit == 3) {
        return low + low + low;
    }
    if (digit == 4) {
        return low + mid;
    }
    if (digit == 5) {
        return mid;
    }
    if (digit == 6) {
        return mid + low;
    }
    if (digit == 7) {
        return mid + low + low;
    }
    if (digit == 8) {
        return mid + low + low + low;
    }
    if (digit == 9) {
        return low + high;
    }
    if (digit == 0) {
        return "";
    }
}

void getRomanFromArabic() {
    str answers[ARRAY_SIZE] = {"", "", "", ""}; //An  array of string to hold the output from the convert function.
    int userNum;
    str strUserNum;

    print << "";
    print << "Enter an arabic number between 1 and 100: ";
    input >> strUserNum;

    userNum = std::stoi(strUserNum);

    if (userNum < MIN_INPUT || userNum > MAX_INPUT) {
        print << "\nInvalid Value. Number must be between 1 and 100" << nl;
        return;
    }

    int thous = userNum / 1000;

    int hund = userNum % 1000 / 100;

    int tens = userNum % 100 / 10;

    int ones = userNum % 10 / 1;

    answers[0] = convert(thous, "M", "M", "M");
    answers[1] = convert(hund, "C", "D", "M");

    answers[2] = convert(tens, "X", "L", "C");
    answers[3] = convert(ones, "I", "V", "X");

    print << answers[0] << answers[1] << answers[2];
    print << answers[3] << nl;
    print << nl;
}

str getArabicFromRoman() {
    input.clear();
    while (input.get() != '\n');
    char roman_Numeral;
    int arabic_Numeral = 0;

    print << "Enter the Roman Numeral in Capital letters (e.g. CCXIX) : ";
    while (input.get(roman_Numeral)) {

        if (arabic_Numeral > 100) {
            print << "\nInvalid Value. Number must be  between I and C" << nl;
            return "";
        } else if (roman_Numeral == 'C') {
            roman_Numeral = input.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D') {
                arabic_Numeral = arabic_Numeral - 100;
            } else {
                arabic_Numeral = arabic_Numeral + 100;
            }

        } else if (roman_Numeral == 'L') {
            roman_Numeral = input.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D'
                || roman_Numeral == 'C') {
                arabic_Numeral = arabic_Numeral - 50;
                continue;
            } else {
                arabic_Numeral = arabic_Numeral + 50;
                continue;
            }
        } else if (roman_Numeral == 'X') {
            roman_Numeral = input.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D'
                || roman_Numeral == 'C' || roman_Numeral == 'L') {
                arabic_Numeral = arabic_Numeral - 10;
                continue;
            } else {
                arabic_Numeral = arabic_Numeral + 10;
                continue;
            }
        } else if (roman_Numeral == 'V') {
            roman_Numeral = input.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D'
                || roman_Numeral == 'C' || roman_Numeral == 'L'
                || roman_Numeral == 'X') {
                arabic_Numeral = arabic_Numeral - 5;
                continue;
            } else {
                arabic_Numeral = arabic_Numeral + 5;
                continue;
            }
        } else if (roman_Numeral == 'I') {
            roman_Numeral = input.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D'
                || roman_Numeral == 'C' || roman_Numeral == 'L'
                || roman_Numeral == 'X' || roman_Numeral == 'V') {
                arabic_Numeral = arabic_Numeral - 1;
                continue;
            } else {
                arabic_Numeral = arabic_Numeral + 1;
                continue;
            }
        } else
            break;
    }
    return std::to_string(arabic_Numeral);
}

int main() {
    bool run = true;
    while (run) {
        print << "Enter 0 to exit, 1 to convert from Arabic to Roman or 2 to convert from Roman to Arabic\n";
        str operation;
        input >> operation;

        if (operation == "0") {
            run = false;
        } else if (operation == "1") {
            getRomanFromArabic();
        } else if (operation == "2") {
            print << getArabicFromRoman();
        } else {
            print << "Unknown command\n";
        }
    }
}