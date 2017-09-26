/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
// Version 1.1
// 2017/05/30
// Samantha West
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// CS          05/29                         removed sict::
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

const int MAX_NAME_LENGTH = 40;
const int MIN_SIN = 100000000;
const int MAX_SIN = 999999999;
const int MAX_YRS = 4;

namespace sict {

    class CRA_Account {
        char famName[MAX_NAME_LENGTH + 1];
        char givName[MAX_NAME_LENGTH + 1];
        int sinNumb;
        int m_year[MAX_YRS];
        double m_balance[MAX_YRS];
        int m_years;
    public:
        void set(const char* familyName, const char* givenName, int sin);
        bool isValid() const;
        void display() const;
        void set(int year, double balance);
    };
}
#endif 

