#include <iostream>
#include <string>

int main() {
    std::cout << "Enter number from 1 to 1000 including" << std::endl;
    std::string numberStr;
    int number;

    if (std::cin.peek() == '\n') {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    std::getline(std::cin, numberStr);

    for (char i : numberStr) {
        if (!isdigit(i)) {
            std::cout << "Invalid input" << std::endl;
            return 0;
        }
    }

    number = std::stoi(numberStr);

    if (number < 1 or number > 1000) {
        std::cout << "invalid range" << std::endl;
    }

    std::cout << "Number: " << number << std::endl;
}