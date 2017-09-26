/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 1.1
// 2017/06/02
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

#include <iostream>
#include <cstring>
#include <math.h>
#include "CRA_Account.h"
using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		if (sin >= MIN_SIN && sin <= MAX_SIN) {
			sinNumb = sin;
            strncpy(givName, givenName, MAX_NAME_LENGTH);
			strncpy(famName, familyName,MAX_NAME_LENGTH);
            givName[MAX_NAME_LENGTH] = '\0';
            famName[MAX_NAME_LENGTH] = '\0';
		}
		else {
            
			// object becomes empty state
			sinNumb = 0;
		}
	}

	bool CRA_Account::isValid() const {
			bool valid = true; 
			int array[9];
			int checkNumb;
			int sumTemp = 0;
			// counter variables
			int mod = 100;
			int div = 10;
			int mult = 0;

            if (sinNumb != 0) {
                // isolate the check number
                checkNumb = sinNumb % 10;

                // gathering first set of alternatives
                for (int i = 0; i < 8; i++) {
                    array[i] = (sinNumb % mod) / div;
                    mod *= 10;
                    div *= 10;
                }

                //isolating alternatives with more then 1 digit to be added 
                for (int i = 0; i < 7; i++) {
                    if (array[i] >= 10) {
                        sumTemp = ((array[i] * 2) / 10) + ((array[i] * 2) % 10);
                        i++;
                    }
                    else {
                        sumTemp += array[i];
                        i++;
                    }
                }
                // adding other alternatives
                sumTemp += array[1] + array[3] + array[5] + array[7];
                // searching for highest integer multiple of 10
                while (mult < sumTemp) {
                    mult += 10;
                }
                // validate check number, taking highest integer multiple of 10 and subtracting check number
                sumTemp = mult - sumTemp;

                if (sumTemp != checkNumb) {
                    valid = false;
                }
            }
            else {
                valid = false;
            }
		return valid;
	}

	void CRA_Account::display() const {
		if (sinNumb != 0) {
            cout << "Family Name: " << famName << endl;
            cout << "Given Name : " << givName << endl;
            cout << "CRA Account: " << sinNumb << endl;

            cout.setf(ios::fixed);
            cout.precision(2);

			for (int i = 0; i < MAX_YRS; i++) {
				cout << "Year (" << m_year[i] << ") ";
				if (m_balance[i] > 2) {
					cout << "balance owing: " << m_balance[i] << endl;
				}
				else if (m_balance[i] < -2) {
					cout << "refund due: " << fabs(m_balance[i]) << endl;
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}
		} 
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	void CRA_Account::set(int year, double balance) {
        int i = m_years;
		if (sinNumb != 0) {
            m_year[i] = year;
            m_balance[i] = balance;
            m_years = m_years + 1;
		}
	}
}
