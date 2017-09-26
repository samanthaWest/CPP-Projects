// OOP244 Workshop 8: Virtual Functions
// File: SavingsAccount.cpp
// Date: 2017/07/20th
// Author : Samantha West (128111168)
// Description:
// Base account class, derived savings class and derived checkings class used
// too hold banking information for each person. 
///////////////////////////////////////////////////
#include "SavingsAccount.h"
#include <iostream>
using namespace std;

namespace ict{ 
	
    // Default constructor
    SavingsAccount::SavingsAccount() 
    {
        interestRate = 0;
    }

    // Constructor receiving 2 parameters
    SavingsAccount::SavingsAccount(double initialBalance, double initialValue) : Account (initialBalance)
    {
        (initialValue > 0) ? interestRate = (initialValue * 100) : interestRate = 0;
    }

    // Calculate interest on savings account
    double SavingsAccount::calculateInterest()
    {
        return (getBalance() * (interestRate / 100));
    }

    // Display savings account information
    ostream& SavingsAccount::display(std::ostream& os)
    {
        os << fixed;
        os.precision(2);
	os << "Account type: Saving" << endl;
        os << "Balance: $ " << getBalance() << endl;
        os << "Interest Rate (%): " << interestRate << endl;
        return os;
    }
}