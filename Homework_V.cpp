#include <iostream>
#include <string>

#define print std::cout
#define input std::cin
#define nl std::endl

float getGrossSalary();

int getDependantCount();

float getSocialTax(float salary);

float getTaxFreeMinimum(float salary);

int getTaxFreeForDependant(int count);

int main() {
    print << "This program calculates your salary but it does not very precisely, so don't be confused :)" << nl;
    float grossSalary = getGrossSalary();
    float socialTax = getSocialTax(grossSalary);
    float taxFreeMinimum = getTaxFreeMinimum(grossSalary);
    grossSalary -= socialTax;
    if (taxFreeMinimum == grossSalary) {
        print << "Your netto is equal to " << grossSalary << nl;
    } else {
        print << "Your netto is equal to " << grossSalary - (grossSalary * 0.3) << nl;
    }

    getchar();
    return 0;
}

float getTaxFreeMinimum(float salary) {
    int dependantCount = getDependantCount();
    int taxFreeForDependant = getTaxFreeForDependant(dependantCount);

    if (taxFreeForDependant >= salary) {
        return salary;
    } else {
        return salary - taxFreeForDependant;
    }
}

int getTaxFreeForDependant(int count) {
    return count * 250;
}

float getSocialTax(float salary) {
    return salary * 0.11;
}

int getDependantCount() {
    print << "Enter dependant count: ";
    int dependantCount;
    input >> dependantCount;
    return dependantCount;
}

float getGrossSalary() {
    print << "Enter your gross salary: ";
    float grossSalary;
    input >> grossSalary;

    return grossSalary;
}
