// OOP244 Workshop 8: Virtual Functions (HOME)
// File: SavingsAccount.h
// Date: 2017/07/16
// Author : Samantha West (128111168)
// Description:
// Base account class, derived savings class and derived checkings class used
// too hold banking information for each person. 
///////////////////////////////////////////////////
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"
using namespace std;

namespace ict{
	class SavingsAccount : public Account{
		private:
    		double interestRate; // interest rate (percentage) 
		public:
            SavingsAccount();
            SavingsAccount(double, double);
            double calculateInterest();
            ostream& display(std::ostream& os);
   };
};
#endif
