/**********************************************************
// Workshop 5: Member Operator Overloads
// Fraction.cpp
// 2017/06/18
// Samantha West
// Description
// Stores a single fraction in an object and uses member functions
// and overloaded operators to perform mathematical tasks on fractions.
**********************************************************/
#include <iostream>
#include "Fraction.h"
using namespace std;

namespace sict {

    Fraction::~Fraction() {
    }
    // Constructor #1 (receives no params)
    Fraction::Fraction() {
        numerator = 0;
        denominator = 0;
    }

    // Constructor #2 (receives 2 params)
    Fraction::Fraction(int num, int den) {
        bool valid = num > 0 && den > 0;
        if (valid) {
            numerator = num;
            denominator = den;
            reduce();
            if (denominator / gcd() == numerator || denominator / gcd() == 1) {
                reduce();
            }
        }
        else {
            *this = Fraction();
        }
    }

    // max returns the maximum of the numerator and denominator
    int Fraction::max() const {
        int max = denominator;
        if (denominator < numerator) {
            max = numerator;
        }
        return max;
    }

    // min returns the maximum of the numerator and denominator
    int Fraction::min() const {
        int min = numerator;
        if (numerator > denominator) {
            min = denominator;
        }
        return min;
    }

    // gcd returns the greatest common divisor of num and denom
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
    void Fraction::reduce() {
        Fraction temp;
        temp.numerator = numerator / gcd();
        temp.denominator = denominator / gcd();
        denominator = temp.denominator;
        numerator = temp.numerator;
    }

    // display inserts num/denom into the output stream
    void Fraction::display() const {
        if (isEmpty() == true) {
            if (denominator == 1) {
                cout << numerator;
            }
            else {
                cout << numerator << "/" << denominator;
            }
        }
        else {
            cout << "no fraction stored";
        }
    }

    // isEmpty returns true if Fraction object is in a safe empty state
    bool Fraction::isEmpty() const {
        bool valid = denominator > 0 && numerator > 0;
        return valid;
    }

    // + operator adds the rhs to the current object and reduces the result
    Fraction Fraction::operator+(const Fraction& frac)const{
        Fraction temp = *this;
        temp += frac;
        return temp;
    }

    // * operator multiples current object and receiving argument
    Fraction Fraction::operator*(const Fraction& frac)const {
        Fraction temp;
        bool valid = isEmpty() && frac.isEmpty();
        if (valid) {
            temp.numerator = (numerator * frac.denominator) + (frac.numerator * denominator);
            temp.denominator = (denominator * frac.denominator);
            temp.reduce();
        }
        else {
            temp = Fraction();
        }
        return temp;
    }

    // == checks for equal values between current object & receiving argument
    bool Fraction::operator==(const Fraction& frac)const {
        bool valid = isEmpty() && frac.isEmpty();
        if (valid) {
            valid = denominator == frac.denominator;
            valid = numerator == frac.numerator;
        }
        return valid;
    }
    // != checks for not equal values between current object & receiving argument
    bool Fraction::operator!=(const Fraction& frac)const {
        bool valid = isEmpty() && frac.isEmpty();
        if (valid) {
            valid = denominator != frac.denominator;
            valid = numerator != frac.numerator;
        }
        return valid;
    }

    // += adds parameter to a current object returning referance of current object
    Fraction& Fraction::operator+=(const Fraction& frac) {
        bool valid = isEmpty() && frac.isEmpty();
        if (valid) {
            *this = *this*frac;
        }
        else {
            *this = Fraction();
        }
        return *this;
    }
}
        


