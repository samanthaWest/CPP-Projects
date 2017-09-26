// OOP244 Workshop 8: Virtual Functions (HOME)
// File: Account.h
// Date: 2017/07/16
// Author : Samantha West (128111168)
// Description:
// Base account class, derived savings class and derived checkings class used
// too hold banking information for each person. 
///////////////////////////////////////////////////
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
using namespace std;

namespace ict{
	class Account{
		private:
			double balance; // data member that stores the balance
		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance
   		public:
            Account();
            Account(double);
            virtual void credit(double); // withdraws money from account
            virtual bool debit(double); // credits money to account
            // pure virtual function
            virtual ostream& display(std::ostream& os) = 0;
   };
};
#endif
