/* Lab 6: Classes with Resources (HOME)
Filename: Contact.cpp
Date: 2017/06/25
Name: Samantha West
Student ID: 128111168
Description: Creating object of type Contact to
valid and store contact information including
name, list of phone numbers and total amount of numbers.
Displays phone numbers in proper format.
*//////////////////////////////////////////////
///////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;

namespace sict {

    // Constructor #1 (no params)
    Contact::Contact() {
        name[MAX_CHARACTERS - MAX_CHARACTERS] = '\0';
        phoneNumbers = 0;
        numbCount = 0;
    }

    // Constructor #2 (3 params)
    Contact::Contact(const char* fullName, const long long* phoneNumb, int totalNumb) {
        bool valid = fullName != nullptr && strcmp(fullName, "") != 0;
        if (valid) {
            numbCount = totalNumb;
            set(fullName, phoneNumb, totalNumb);
        }
        else {
            *this = Contact();
        }
    }

    // Copy Constructor: copy from source object to newly created object of same type
    Contact::Contact(const Contact&src) {
        phoneNumbers = nullptr;
        operator=(src);
    }

    // Copy Assignment Operator: copy existing data to exisiting object
    Contact& Contact::operator=(const Contact&src) {
        // Check for self assignment
        if (this != &src) {
            strncpy(name, src.name, MAX_CHARACTERS);
            name[MAX_CHARACTERS - 1] = '\0';
            numbCount = src.numbCount;
            // deallocate previously allocated memory
            delete[] phoneNumbers;
            // allocate new memory if needed
            if (src.phoneNumbers != nullptr) {
                phoneNumbers = new long long[numbCount];

                for (int i = 0; i < numbCount; i++) {
                    phoneNumbers[i] = src.phoneNumbers[i];
                }
            }
            else {
                phoneNumbers = nullptr;
            }
        }
        return *this;
    }

    // Overloaded += operator which resizes array and copies new phone number to increased array
    Contact& Contact::operator+=(const long long& src) {
        bool valid = numbDiv(src);
        if (valid) {
            numbCount++;
            Contact temp;
            temp.phoneNumbers = new long long[numbCount];   
            for (int i = 0; i < numbCount; i++) {
                temp.phoneNumbers[i] = phoneNumbers[i];
            }
            temp.phoneNumbers[numbCount-1] = src;

            delete[] phoneNumbers;
            phoneNumbers = new long long[numbCount];
            for (int i = 0; i < numbCount; i++) {
                phoneNumbers[i] = temp.phoneNumbers[i];
            }
        }
            return *this;
    }

    // Accept 3 parameters to set instance variables for Contact object
    void Contact::set(const char* fullName, const long long* phoneNumb, int totalNumb) {
        // shallow copy
        strncpy(name, fullName, MAX_CHARACTERS);
        name[MAX_CHARACTERS - 1] = '\0';
        // deep copying
        phoneNumbers = new long long[totalNumb];
        for (int i = 0; i < totalNumb; i++) {
            if (numbDiv(phoneNumb[i])) {
                // deep copying
                phoneNumbers[numbCount] = phoneNumb[i];
                numbCount++;
            }
        }
    }


    // Validate phone number and return validity
    bool Contact::numbDiv(long long phoneNumb) {
        // checking for proper length of phone number include (country code, area code, number // min 11 max 12)
        bool valid = phoneNumb > 9999999999 && phoneNumb < 1000000000000;

        if (valid) {
            // checking for valid 12 digit phone number
            if (valid && phoneNumb > 100000000000) {
                long long checkNumb1 = (phoneNumb % 10000000) / 1000000;
                long long checkNumb2 = ((phoneNumb / 10000000) % 1000) / 100;
                long long checkNumb3 = (phoneNumb / 10000000000) % 10;
                long long checkNumb4 = (phoneNumb / 10000000000) / 10;
                valid = checkNumb1 != 0 && checkNumb2 != 0 && checkNumb3 != 0 && checkNumb4 != 0;
            }
            // checking for valid 11 digit phone number
            else {
                long long checkNumb1 = (phoneNumb % 10000000) / 1000000;
                long long checkNumb2 = ((phoneNumb / 10000000) % 1000) / 100;
                long long checkNumb3 = phoneNumb / 10000000000;
                valid = checkNumb1 != 0 && checkNumb2 != 0 && checkNumb3 != 0;
            }
        }
        return valid;
    }

    // Check if object is in empty state
    bool Contact::isEmpty() const {
        bool valid = phoneNumbers == 0 || name == nullptr;
        return valid;
    }

    // Display contact information
    void Contact::display() const {
        bool valid = isEmpty();
        if (valid) {
            cout << "Empty contact!" << endl;
        }
        else {
            cout << name << endl;
            format();
        }
    }

    // Display phone number in proper format
    void Contact::format() const {
        for (int i = 0; i < numbCount; i++) {
            // format for 12 digit phone number
            if (phoneNumbers[i] > 99999999999 && phoneNumbers[i] < 999999999999) {
                cout << "(+" << 114164567890 / 10000000000 << ") "
                 << (114164567890 / 10000000) % 1000 << " "
                 << (114164567890 % 10000000) / 10000 << "-"
                 << (114164567890 % 10000000) % 10000 << endl;
            }
            // format for 11 digit phone number
            if (phoneNumbers[i] > 10000000000 && phoneNumbers[i] < 99999999999) {
                cout << "(+" << phoneNumbers[i] / 10000000000 << ") " <<
                    ((phoneNumbers[i] / 10000000) % 1000) << " " <<
                    (phoneNumbers[i] % 10000000) / 10000 << "-" <<
                    (phoneNumbers[i] % 10000000) % 10000 << endl;
            }
        }
    }

    // Constructor
    Contact::~Contact() {
        delete[] phoneNumbers;
    }
}