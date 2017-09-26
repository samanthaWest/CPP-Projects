/**********************************************************
// Workshop 4: Constructors
// Passenger.h
// Version 1.1
// 2017/06/09
// Samantha West
// Description
// Validate data for passengers of an airline through the process of
// defining special member functions, defining default constructors
// and overloading constructors. Comparing passenger travel dates & destinations.
**********************************************************/

#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

const int MAX_CHAR = 32;

namespace sict {

    class Passenger {
        char fullname[MAX_CHAR];
        char destination[MAX_CHAR];
        int d_year;
        int d_month;
        int d_day;
    public:
        Passenger();
        Passenger(const char*, const char*);
        Passenger(const char*, const char*, int, int, int);
        const char* name() const;
        bool canTravelWith(const Passenger&) const;
        bool isEmpty() const;
        void display() const;
    };
}
#endif 


