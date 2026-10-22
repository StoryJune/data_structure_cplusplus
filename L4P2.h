/*
Lab 4 
Problem 2
CS 008 - Jason Li
*/

#include <iostream>
#include <string>

using namespace std;


// Use the node class for the linked list
class node {
    public:
        int coefficient; // Coefficient of the term
        int exponent; // Exponent of the term
        node* link; // Pointer to the next node

        node(int c, int e) {
            coefficient = c;
            exponent = e;
            link = nullptr;
        }
};

// Linked list class for creating a polynomial
class Polynomial {
    private:
        node* head; // Head pointer of the linked list
        int count; // Number of terms

    public:
        // Default constructor
        Polynomial() : head(nullptr), count(0) {}

        // Copy constructor
        Polynomial(const Polynomial& other){
            
        }
        
        // Assignment operator 
        Polynomial& operator=(const Polynomial& other){
            
        }
        
        ~Polynomial(); // Destructor
    
        // The polynomial should be created in descending order of exponents.
        void insertTerm(int coefficient, int exponent);
        
        // Clear the entire linked list
        void clear(){
            
        }
        
        // Display the polynomial
        void display(){
            for(node* walk = head; walk != nullptr; walk++){
                cout << walk->coefficient << "^" << walk->exponent << " ";
            }
            cout << endl;
        }
    
        // Addition operator
        Polynomial operator+(const Polynomial& other) const;
};

// Read a polynomial from a file
Polynomial readPolynomial(const string& filename);