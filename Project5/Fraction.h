/**********************************************************
// Workshop 5: Member Operator Overloads
// Fraction.h
// 2017/06/18
// Samantha West
// Description
// Stores a single fraction in an object and uses member functions
// and overloaded operators to perform mathematical tasks on fractions.
**********************************************************/
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {
    class Fraction {
        int numerator;
        int denominator;
        int gcd() const; // returns the greatest common divisor of num and denom
        int max() const; // returns the maximum of num and denom
        int min() const; // returns the minimum of num and denom
        void reduce();   // simplifies a Fraction by dividing the 
                         // numerator and denominator to their greatest common divisor 
    public:
        Fraction();
        Fraction(int, int);
        void display() const;
        bool isEmpty() const;
        // Overloaded Operators
        Fraction operator+(const Fraction&);
        Fraction operator*(const Fraction&);
        bool operator==(const Fraction&);
        bool operator!=(const Fraction&);
        Fraction& operator+=(const Fraction&);
    };
}
#endif