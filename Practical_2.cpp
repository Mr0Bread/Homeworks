#include <iostream>
#include <string>

#define print std::cout
#define nl std::endl
#define get std::cin
#define str std::string

int main() {
    struct Birthday {
        int day;
        int month;
        int year;

        void printData() {
            print << "Day of birth: " + std::to_string(this->day) << nl;
            print << "Month of birth: " + std::to_string(this->month) << nl;
            print << "Year of birth: " + std::to_string(this->year) << nl;
        }
    };

    struct Person {
        str name;
        str surname;
        Birthday birthday;
        str cityOfBirth;

        void printData() {
            print << "Name: " + this->name << nl;
            print << "Surname: " + this->surname << nl;
            this->birthday.printData();
            print << "City of birth: " + this->cityOfBirth << nl;
        }
    };

    print << "Enter quantity of persons to create\n> ";
    int quantity;
    get >> quantity;

    auto personList = new Person[quantity];

    for (int i = 0; i < quantity; ++i) {
        print << "Enter name\n> ";
        str name;
        get >> name;

        print << "Enter surname\n> ";
        str surname;
        get >> surname;

        print << "Enter day of birth\n> ";
        int day;
        get >> day;

        print << "Enter month of birth\n> ";
        int month;
        get >> month;

        print << "Enter year of birth\n> ";
        int year;
        get >> year;

        print << "Enter city of birth\n> ";
        str city;
        get >> city;

        auto person = Person{name, surname, {day, month, year}, city};
        personList[i] = person;
    }

    for (int j = 0; j < quantity; ++j) {
        personList[j].printData();
        print << nl;
    }

    getchar();
    return 0;
}
