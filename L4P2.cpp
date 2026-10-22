/*
Lab 4 
Problem 2
CS 008 - Jason Li
*/

#include "L4P2.h"

int main() {
    string filename1;
    string filename2;
    cout << "Enter filename1: ";
    cin >> filename1;
    Polynomial poly = readPolynomial(filename1);
    cout << "Polynomial 1: ";
    poly.display();
    // Read the second filename
    cout << "\nEnter filename2: ";
    cin >> filename2;
    Polynomial poly2 = readPolynomial(filename2);
    cout << "Polynomial 2: ";
    poly2.display();
    // Add the two polynomials
    Polynomial poly3 = poly + poly2;
    cout << "\nPolynomial 1 + Polynomial 2: ";
    poly3.display();
    return 0;
}