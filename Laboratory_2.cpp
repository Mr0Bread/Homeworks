#include <iostream>
#include <fstream>
#include <vector>
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
    short int id;
    Birthday birthday;
    str date;
    short int salary;
    str hometown;
    str country;
    str workPlace;
};

void printPerson(const Person &person);

int main() {
    int personCount;
    std::vector<int> indexesToDelete;

    do {
        print << "Enter number of persons to fill from 1 to 9: ";
        input >> personCount;
    } while (personCount < 1 or personCount > 9);

    auto *persons = new Person[personCount];

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

        persons[i] = person;
    }

    for (int i = 0; i < personCount; i++) {
        print << "\n\nPerson number " << i << ":" << nl;

        printPerson(persons[i]);

        print << "\n\n";
    }
    bool run = true;
    while (run) {
        print
                << "Enter operation you want to perform 'search' or 'delete' without quotes or enter 'exit' to exit from program\n> ";
        str operation;
        input >> operation;

        if (operation == "exit") {
            run = false;
        } else if (operation == "search") {
            print << "Enter data to search by(It can be Name, ID, Birthday, Salary, Country or Work place)\n> ";
            str keyword;
            input >> keyword;

            for (int i = 0; i < personCount; i++) {
                if (persons[i].name == keyword
                    or std::to_string(persons[i].id) == keyword
                    or persons[i].date == keyword
                    or std::to_string(persons[i].salary) == keyword
                    or persons[i].country == keyword
                    or persons[i].workPlace == keyword) {
                    print << "System found match!\n";

                    printPerson(persons[i]);

                    print << "\n\n";
                }
            }
        } else if (operation == "delete") {
            print << "Enter Surname of person you want to delete or ID\n> ";
            str keyword;
            input >> keyword;

            for (int i = 0; i < personCount; i++) {
                if (persons[i].surname == keyword
                    or std::to_string(persons[i].id) == keyword) {
                    indexesToDelete.push_back(i);
                }
            }
            personCount -= indexesToDelete.size();
            auto *tempPersons = new Person[personCount];

            for (int i = 0, k = 0; i < personCount + indexesToDelete.size(); i++) {
                for (int index : indexesToDelete) {
                    if (i != index) {
                        tempPersons[k] = persons[i];
                        k++;
                    }
                }
            }

            persons = new Person[personCount];

            for (int i = 0; i < personCount; i++) {
                persons[i] = tempPersons[i];
            }

            delete[] tempPersons;

            for (int i = 0; i < personCount; i++) {
                printPerson(persons[i]);
                print << "\n\n";
            }
        } else {
            print << "Wrong input" << nl;
        }
    }

    delete[] persons;

    return 0;
}

void printPerson(const Person &person) {

    print << "Name is " << person.name << " " << person.surname << nl;
    print << "ID is equal to " << person.id << nl;

    print << "Was born in " << person.birthday.year << '.' << person.birthday.month << '.' <<
          person.birthday.day << nl;

    print << "Born in " << person.country << ", " << person.hometown << nl;

    print << "Works at " << person.workPlace;

}
