#include <iostream>
using namespace std;
int main()
{
    int test;
    cin >> test;
    cin.clear();
    while (cin.get() != '\n');
    char roman_Numeral;
    int arabic_Numeral = 0;

    cout << "Enter the Roman Numeral in Capital letters (e.g. XL) : ";
    while (cin.get(roman_Numeral))
    {

        if (arabic_Numeral > 100)
        {
            cout << "\nInvalid Value. Number must be  between I and C" << endl;
            return 0;
        }

        else if (roman_Numeral == 'C')
        {
            roman_Numeral = cin.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D')
            {
                arabic_Numeral = arabic_Numeral - 100;
            }
            else
            {
                arabic_Numeral = arabic_Numeral + 100;
            }

        }

        else if (roman_Numeral == 'L')
        {
            roman_Numeral = cin.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D'
                || roman_Numeral == 'C')
            {
                arabic_Numeral = arabic_Numeral - 50;
                continue;
            }
            else
            {
                arabic_Numeral = arabic_Numeral + 50;
                continue;
            }
        }

        else if (roman_Numeral == 'X')
        {
            roman_Numeral = cin.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D'
                || roman_Numeral == 'C' || roman_Numeral == 'L')
            {
                arabic_Numeral = arabic_Numeral - 10;
                continue;
            }
            else
            {
                arabic_Numeral = arabic_Numeral + 10;
                continue;
            }
        }

        else if (roman_Numeral == 'V')
        {
            roman_Numeral = cin.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D'
                || roman_Numeral == 'C' || roman_Numeral == 'L'
                || roman_Numeral == 'X')
            {
                arabic_Numeral = arabic_Numeral - 5;
                continue;
            }
            else
            {
                arabic_Numeral = arabic_Numeral + 5;
                continue;
            }
        }

        else if (roman_Numeral == 'I')
        {
            roman_Numeral = cin.peek();
            if (roman_Numeral == 'M' || roman_Numeral == 'D'
                || roman_Numeral == 'C' || roman_Numeral == 'L'
                || roman_Numeral == 'X' || roman_Numeral == 'V')
            {
                arabic_Numeral = arabic_Numeral - 1;
                continue;
            }
            else
            {
                arabic_Numeral = arabic_Numeral + 1;
                continue;
            }
        }

        else
            break;
    }
    cout << arabic_Numeral << endl;
    return 0;
}