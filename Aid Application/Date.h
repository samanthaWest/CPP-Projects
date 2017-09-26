/* Milestone 5: AMAPRODUCT & AMAPERISHABLE CLASSES
Student: Samantha West (128111168)
Filename: Date.h
Date: 2017/07/20
Description: Aid management releif app.
//////////////////////////////////////////////
*/
#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>
using namespace std;

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

namespace sict {

    // Milestone 1: The Date Class 
    class Date {
    private:
        int year_;
        int mon_;
        int day_;
        int readErrorCode_;

        int value()const;
        void errCode(int errorCode) { readErrorCode_ = errorCode; }
    public:
        Date();
        Date(int, int, int);
        int mdays()const;
        int errCode() const { return readErrorCode_; }
        bool bad() const { bool valid = errCode() != 0; return valid; }
        bool operator==(const Date& D) const { bool valid = this->value() == D.value();  return valid; }
        bool operator!=(const Date& D) const { bool valid = this->value() != D.value();  return valid; }
        bool operator<(const Date& D) const { bool valid = this->value() < D.value();  return valid; }
        bool operator>(const Date& D) const { bool valid = this->value() > D.value();  return valid; }
        bool operator<=(const Date& D) const { bool valid = this->value() <= D.value();  return valid; }
        bool operator>=(const Date& D) const { bool valid = this->value() >= D.value();  return valid; }

        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr) const;
    };

    std::ostream& operator<<(ostream& os, const Date& d);
    std::istream& operator >> (istream& is, Date& d);
}
#endif
