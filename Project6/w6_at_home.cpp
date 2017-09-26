#include <iostream>
#include "Contact.h"

/* Lab 6: Classes with Resources (HOME)
Filename: w6_at_home.cpp
Date: 2017/06/25
Name: Samantha West
Student ID: 128111168
Description: Creating object of type Contact to
valid and store contact information including
name, list of phone numbers and total amount of numbers.
Displays phone numbers in proper format.
*//////////////////////////////////////////////
///////////////////////////////////////////////
using namespace std;
using namespace sict;

int main() {

    sict::Contact theContact("John Doe", nullptr, 0); // sict:: intentional
    theContact.display();
    theContact += 14161234567LL;
    theContact += 14162345678LL;
    theContact += 14163456789LL;
    theContact += 114164567890LL;
    theContact.display();

    cout << endl << "Testing! Please wait:" << endl;

    for (int i = 1; i <= 5000000; i++)
    {
        Contact temp = theContact;
        theContact = temp;
        theContact = theContact;
        if (!(i % 10000))
            cout << ".";
        if (!(i % 500000))
            cout << endl;
    }

    cout << endl;
    theContact.display();

    return 0;
}