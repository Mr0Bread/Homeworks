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

    Birthday() {
        day = 0;
        month = 0;
        year = 0;
    }

    Birthday(unsigned int day, unsigned int month, unsigned int year) : day(day), month(month), year(year) {}
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

    auto* persons = new Person[personCount];

    for (int i = 0; i < personCount; i++) {
        Person person;

        print << "Enter name: ";
        input >> person.name;

        print << "Enter surname: ";
        input >> person.surname;

        print << "Enter id: ";
        input >> person.id;

        Birthday birthday;
        print << "Enter birthday day: ";
        input >> birthday.day;
        print << "Enter birthday month: ";
        input >> birthday.month;
        print << "Enter birthday year: ";
        input >> birthday.year;

        person.birthday = birthday;

        print << "Enter date: ";
        input >> person.date;

        print << "Enter salary: ";
        input >> person.salary;

        print << "Enter hometown: ";
        input >> person.hometown;

        print << "Enter country: ";
        input >> person.country;

        print << "Enter workPlace: ";
        input >> person.workPlace;
    }

    delete [] persons;

    return 0;
}