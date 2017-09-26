/* Lab 6: Classes with Resources (HOME)
Filename: Contact.h
Date: 2017/06/25
Name: Samantha West
Student ID: 128111168
Description: Creating object of type Contact to
valid and store contact information including
name, list of phone numbers and total amount of numbers.
Displays phone numbers in proper format.
*//////////////////////////////////////////////
///////////////////////////////////////////////
#ifndef CONTACT_H_
#define CONTACT_H_

#define MAX_CHARACTERS 20

namespace sict {

    class Contact {
        // null byte included
        char name[MAX_CHARACTERS];
        long long *phoneNumbers;
        int numbCount;
        bool numbDiv(long long);
        void set(const char*, const long long*, int);
    public:
        Contact();
        Contact(const char*, const long long*, int);
        ~Contact();
        bool isEmpty() const;
        void display() const;
        void format() const;
        Contact(const Contact&src);
        Contact& operator=(const Contact&src);
        Contact& operator+=(const long long& src);
    };
}
#endif
