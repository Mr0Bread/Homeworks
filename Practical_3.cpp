#include <iostream>
#include <ctime>

#define print std::cout
#define nl std::endl

int getDaysToXmas() {
    time_t now;
    struct tm xmas{};
    double seconds;

    time(&now);

    xmas = *localtime(&now);

    xmas.tm_hour = 0;
    xmas.tm_min = 0;
    xmas.tm_sec = 0;
    xmas.tm_mon = 11;
    xmas.tm_mday = 26;

    seconds = difftime(mktime(&xmas), now);

    return (int)seconds / 86400;

}

int getDaysToBirthday() {
    time_t now;
    struct tm bd{};
    double seconds;

    time(&now);

    bd = *localtime(&now);

    bd.tm_hour = 0;
    bd.tm_mday = 21;
    bd.tm_mon = 9;
    bd.tm_min = 0;
    bd.tm_sec = 0;

    seconds = difftime(mktime(&bd), now);

    return (int)seconds / 86400;
}

int getDaysToEaster() {
    time_t now;
    struct tm easter{};
    double seconds;

    time(&now);

    easter = *localtime(&now);

    easter.tm_sec = 0;
    easter.tm_min = 0;
    easter.tm_mon = 3;
    easter.tm_mday = 19;
    easter.tm_hour = 0;

    seconds = difftime(mktime(&easter), now);

    return (int)seconds / 86400;
}

int main() {
    bool run = true;

    while (run) {
        print << "Enter 1 or 2 or 3 to get some info or 4 to exit" << nl;
        int answer;
        std::cin >> answer;

        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            print << "Invalid output" << nl;
            continue;
        }

        switch (answer) {
            case 1:
                print << "Till xmas is " << getDaysToXmas() << " days" << nl;
                break;
            case 2:
                print << "Till my birthday is " << getDaysToBirthday() << " days" << nl;
                break;
            case 3:
                print << getDaysToEaster() << nl;
                break;
            case 4:
                run = false;
                break;
            default:
                print << "Unknown answer" << nl;
        }
    }

    getchar();
    return 0;
}

