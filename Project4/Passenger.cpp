/**********************************************************
// Workshop 4: Constructors
// Passenger.cpp
// Version 1.1
// 2017/06/09
// Samantha West
// Description
// Validate data for passengers of an airline through the process of
// defining special member functions, defining default constructors
// and overloading constructors. Comparing passenger travel dates & destinations.
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict {

    // Constructor 1 (0 parameters): default, set object to empty state
    Passenger::Passenger() {
        fullname[0] = '\0';
        destination[0] = '0';
        d_day = 0;
        d_month = 0;
        d_year = 0;
    }

    // Constructor 2 (2 parameters): checks for valid data & stores the data in the object or sets object to empty state
    Passenger::Passenger(const char* _name, const char* _destination) {
        if (_name != nullptr && _destination != nullptr && _name > 0 && _destination > 0){
            strncpy(fullname, _name, MAX_CHAR);
            strncpy(destination, _destination, MAX_CHAR);
            fullname[MAX_CHAR -1] = '\0';
            destination[MAX_CHAR - 1] = '\0';
            d_day = 1;
            d_day = 7;
            d_year = 2017;
        }
        else {
            char _tempname[1] = { '\0' };
            char _tempdestination[1] = { '\0' };
            strncpy(fullname, _tempname, 1);
            strncpy(destination, _tempdestination, 1);
        }
    }

    // Constructor 3 (5 parameters): checks for valid data & stores the data in the object or sets object to empty state
    Passenger::Passenger(const char* _name, const char* _destination, int _year, int _month, int _date) {
        if (_name != nullptr && _destination != nullptr &&
            _name > 0 && _destination > 0 && _month >= 1 && _month <= 12
            && _date >= 1 && _date <= 31 && _year >= 2017 && _year <=2020) {
            
            strncpy(fullname, _name, MAX_CHAR);
            strncpy(destination, _destination, MAX_CHAR);
            fullname[MAX_CHAR - 1] = '\0';
            destination[MAX_CHAR - 1] = '\0';
            d_day = _date;
            d_month = _month;
            d_year = _year;
               
        }
        else {
            char _tempname[1] = { '\0' };
            char _tempdestination[1] = { '\0' };
            strncpy(fullname, _tempname, 1);
            strncpy(destination, _tempdestination, 1);
            d_month = 0;
            d_day = 0;
            d_year = 0;
        }
    }

    // Returns addresse of valid passenger name or empty string
    const char* Passenger::name() const {
        return fullname;
    }

    // Compares current object destination & date with parameter destination & date
    bool Passenger::canTravelWith(const Passenger& travelbuddy) const {
        bool valid = (strcmp(destination, travelbuddy.destination)) == 0 && d_day == travelbuddy.d_day
            && d_month == travelbuddy.d_month && d_year == travelbuddy.d_year;
            return valid;
    }

    // check if object is empty state
    bool Passenger::isEmpty() const {
        bool valid = fullname[0] == 0 || destination[0] == 0;
        return valid;
    }
    
    // display objects contents
    void Passenger::display() const {
        cout << fullname << " - " << destination << " on " << d_year << "/0" << d_month << "/" << d_day << endl;
    }
}

