#include <iostream>

#define print std::cout
#define nl std::endl

int main() {
    union Data {
        int i;
        char c;
    };

    Data myByte{};
    myByte.i = 65;
    print << myByte.c;
    myByte.i = 46;
    print << myByte.c;
    myByte.i = 75;
    print << myByte.c;
    myByte.i = 46;
    print << myByte.c << nl;

    getchar();
    return 0;
}