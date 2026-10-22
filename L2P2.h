#include <iostream>

using namespace std;

class BigInteger {
private:
    static const int MAX_DIGITS = 100; // Maximum number of digits
    int digits[MAX_DIGITS];
    int numDigits; // Number of digits currently used
    bool sign; // true for positive number, false for negative number

public:
    // Constructors
    BigInteger();
    BigInteger(int value);
    BigInteger(const char* str);

    // Member functions
    bool isZero() const;
    
    // Operator overloading
    BigInteger operator+(const BigInteger& other) const;
    BigInteger operator-(const BigInteger& other) const;
    bool operator==(const BigInteger& other) const;
    
    // IO Stream operators
    friend ostream& operator<<(ostream& out, const BigInteger& value);
    friend istream& operator>>(istream& in, BigInteger& value);
};

BigInteger::BigInteger(){
    int digit = 0;
    int numDigits = 0;
    bool sign = true;
}

BigInteger::BigInteger(int value){
    int digit = value;
    int numDigits = sizeof(value);
    bool sign = true;
}

BigInteger::BigInteger(const char* str){
    //convert str into int or do str concatenation
}

// Member functions
bool isZero(){
    if(this->digit == 1){
        return true;
    }else{
        return false;
    }
}

// Operator overloading
BigInteger operator+(const BigInteger& other) const{

}

BigInteger operator-(const BigInteger& other) const{

}

bool operator==(const BigInteger& other) const{

}

// IO Stream operators
friend ostream& BigInterger::operator<<(ostream& out, const BigInteger& value){

}

friend istream& BigInterger::operator>>(istream& in, BigInteger& value){

}