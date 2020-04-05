#include <iostream>
#include <string>

#define print std::cout
#define input std::cin
#define nl std::endl
#define str std::string

struct Birthday {
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

struct Person {
    str name;
    str surname;
    unsigned int id;
    Birthday birthday;
    unsigned int date;
    unsigned int salary;
    str hometown;
    str country;
    str workPlace;
};

int main() {
    int personCount;

    do {
        print << "Enter number of persons to fill from 1 to 9: ";
        input >> personCount;
    } while (personCount < 1 or personCount > 9);

    Person persons = *new Person[personCount];

    for (int i = 0; i < personCount; i++) {

    }

    delete persons[];

    return 0;
}