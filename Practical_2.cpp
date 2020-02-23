#include <iostream>
#include <string>

using namespace std;

int main() {
    struct Birthday {
        int day;
        int month;
        int year;

        void printData() {
            cout << "Day of birth: " + std::to_string(this->day) << endl;
            cout << "Month of birth: " + std::to_string(this->month) << endl;
            cout << "Year of birth: " + std::to_string(this->year) << endl;
        }
    };

    struct Person {
        string name;
        string surname;
        Birthday birthday{};
        string cityOfBirth;

        void printData() {
            cout << "Name: " + this->name << endl;
            cout << "Surname: " + this->surname << endl;
            this->birthday.printData();
            cout << "City of birth: " + this->cityOfBirth << endl;
        }
    };

    cout << "Enter quantity of persons to create\n> ";
    int quantity;
    cin >> quantity;

    auto personList = new Person[quantity];

    for (int i = 0; i < quantity; ++i) {
        cout << "Enter name\n> ";
        string name;
        cin >> name;

        cout << "Enter surname\n> ";
        string surname;
        cin >> surname;

        cout << "Enter day of birth\n> ";
        int day;
        cin >> day;

        cout << "Enter month of birth\n> ";
        int month;
        cin >> month;

        cout << "Enter year of birth\n> ";
        int year;
        cin >> year;

        cout << "Enter city of birth\n> ";
        string city;
        cin >> city;

        Person person = Person{name, surname, {day, month, year}, city};
        personList[i] = person;
    }

    for (int j = 0; j < quantity; ++j) {
        personList[j].printData();
        cout << endl;
    }

    delete[] personList;
    
    putchar('\n');
    getchar();
    return 0;
}
