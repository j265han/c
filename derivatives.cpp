// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#ifndef MARMOSET_TESTING
int main();
#endif
void differentiate(double coefficients[], int& degree);
void differentiate(double coefficients[], int& degree) {

    for (int n{ 1 }; n <= degree; n++) {
        coefficients[n - 1] = coefficients[n] * n;
    }
    degree--;
    coefficients[degree] = 0;


    return;
}

#ifndef MARMOSET_TESTING
int main() {
    return 0;
}
#endif

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
