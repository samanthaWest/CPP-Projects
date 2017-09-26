// OOP244 Workshop 8: Virtual Functions (HOME)
// File: Account.cpp
// Date: 2017/07/20th
// Author : Samantha West (128111168)
// Description:
// Base account class, derived savings class and derived checkings class used
// too hold banking information for each person. 
///////////////////////////////////////////////////
#include "Account.h"
using namespace std;

namespace ict {

    // Default constructor
    Account::Account() {
        balance = 1.0;
    }

    // Constructor with 1 parameter 
    Account::Account(double initialDeposit)
    {
        (initialDeposit >= 0) ? balance = initialDeposit : balance = 1.0;
    }

    // Credit to bank account
    void Account::credit(double money)
    {
        balance += money;
    }

    // Debit to bank account
    bool Account::debit(double money)
    {
        bool valid = (balance - money) > 0;
        if (valid == true) {
            balance -= money;
        }
        else {
            return false;
        }
        return valid;
    }

    // Get account balance
	double Account::getBalance() const
	{
		return balance;
	} 

    // Set account balance 
	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}