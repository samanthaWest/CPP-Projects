#include <iostream>
#include <string>
#include "Date.h"
#include "general.h"
namespace sict {

    // Milestone 1: The Date Class
    // Default Constructor
    Date::Date() {
        year_ = 0;
        mon_ = 00;
        day_ = 00;
        readErrorCode_ = NO_ERROR;
    }

    // Constructor with 3 parameters
    Date::Date(int year, int mon, int day) {
        year_ = year;
        mon_ = mon;
        day_ = day;
        readErrorCode_ = NO_ERROR;
    }

    // Returns unique int number based on date, used to compare two dates
    int Date::value()const {
        return year_ * 372 + mon_ * 31 + day_;
    }

    // Returns max days in the current month
    int Date::mdays()const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
        mon--;
        return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
    }

    // Reads data in format YYYY/MM/DD
    std::istream& Date::read(std::istream& istr) {
        // Gar = garbage: to hold garbage "/" input
        char gar;

        istr >> year_ >> gar >> mon_ >> gar >> day_;

        if (istr.fail()) {
            readErrorCode_ = CIN_FAILED;
        }
        else if (year_ < MIN_YEAR || year_ > MAX_YEAR) {
            readErrorCode_ = YEAR_ERROR;

        }
        else if (mon_ < 0 || mon_ > 12) {
            readErrorCode_ = MON_ERROR;
        }
        else if (!(day_ > 0 && day_ <= mdays())) {
            readErrorCode_ = DAY_ERROR;
        }

        return istr;
    }

    // Display date using format YYYY/MM/DD
    std::ostream& Date::write(std::ostream& ostr) const {

        ostr << year_ << "/";
        if (mon_ < 10) {
            ostr << "0" << mon_;
        }
        else {
            ostr << mon_;
        }
        ostr << "/";
        if (day_ < 10) {
            ostr << "0" << day_;
        }
        else {
            ostr << day_;
        }

        return ostr;
    }

    // Overloaded << operator, calls ostream/write member function
    std::ostream& operator<<(ostream& os, const Date& d) {
        d.write(os);
        return os;
    }

    // Overloaded >> operator, calls istream/read member function
    std::istream& operator >> (istream& is, Date& d) {
        d.read(is);
        return is;
    }

}