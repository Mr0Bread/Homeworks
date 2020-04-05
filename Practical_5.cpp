#include <iostream>
#include <string>

#define print std::cout
#define nl std::endl
#define input std::cin

int getLargerOfThreeInts();

int askForIntNum(const char *string);

bool isFirstFloatLarger();

float askForFloatNum(const char string[16]);

bool isCharacterVowel();

char askForChar(const char string[16]);

int main() {
    print << "Now we are getting largest of three integers" << nl;

    int largest = getLargerOfThreeInts();
    print << "The largest is " << largest;

    print << "\n\nNow we are checking if first float is larger than second\n\n";

    if (isFirstFloatLarger()) {
        print << "True" << nl;
    } else {
        print << "False" << nl;
    }

    print << "\nNow we are checking if passed character is vowel\n\n";

    if (isCharacterVowel()) {
        print << "True" << nl;
    } else {
        print << "False" << nl;
    }

    getchar();
    return 0;
}

bool isCharacterVowel() {
    char character = askForChar("Enter character");

    return character == 'a'
           or character == 'e'
           or character == 'i'
           or character == 'o'
           or character == 'u';
}

char askForChar(const char string[16]) {
    print << string << nl;
    char character;
    input >> character;
    return character;
}

bool isFirstFloatLarger() {
    float firstNum = askForFloatNum("Enter first num");
    float secondNum = askForFloatNum("Enter second num");

    return firstNum > secondNum;
}

float askForFloatNum(const char string[16]) {
    print << string << nl;
    float num;
    input >> num;
    return num;
}

int getLargerOfThreeInts() {
    int firstNum = askForIntNum("Enter first num");
    int secondNum;
    int thirdNum;

    do {
        secondNum = askForIntNum("Enter second num");
    } while (secondNum == firstNum);

    do {
        thirdNum = askForIntNum("Enter third num");
    } while (thirdNum == secondNum or thirdNum == firstNum);

    int nums[] {firstNum, secondNum, thirdNum};

    for (int i = 0; i < 2; i++) {
        if (nums[i] < nums[i + 1]) {
            std::swap(nums[i], nums[i + 1]);
            i = -1;
        }
    }

    return nums[0];
}

int askForIntNum(const char *string) {
    print << string << nl;
    int number;
    input >> number;
    return number;
}
