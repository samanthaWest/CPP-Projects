// BTP200 Workshop 8: Virtual Functions (HOME)
// File: CheckingAccount.h
// Date: 2017/07/20th
// Author : Samantha West (128111168)
// Description:
// Base account class, derived savings class and derived checkings class used
// too hold banking information for each person. 
///////////////////////////////////////////////////
#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__
#include "Account.h"

namespace ict{
	class CheckingAccount : public Account {
		private:
			double transactionFee;
            void chargeFee() { setBalance(getBalance() - transactionFee); }
		public:
            CheckingAccount();
            CheckingAccount(double, double);
            bool debit(double);
            void credit(double);
            ostream& display(std::ostream& os);
	};
};
#endif
