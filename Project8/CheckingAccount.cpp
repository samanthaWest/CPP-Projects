// BTP200 Workshop 8: Virtual Functions (HOME)
// File: CheckingAccount.cpp
// Date: 2017/07/20th
// Author : Samantha West (128111168)
// Description:
// Base account class, derived savings class and derived checkings class used
// too hold banking information for each person. 
///////////////////////////////////////////////////
#include "CheckingAccount.h"
namespace ict{    
	
    // Default Constructor
    CheckingAccount::CheckingAccount()
    {
        transactionFee = 0;
    }

    // Constructor receiving 2 parameters
    CheckingAccount::CheckingAccount(double initialBalance, double transFee) : Account(initialBalance)
    {
        (transFee > 0) ? transactionFee = transFee : transactionFee = 0;
    }
    
    // Withdraw money with a charge fee
    bool CheckingAccount::debit(double money)
    {
        bool valid = (getBalance() - money) > 0;
        if (valid == true) {
            chargeFee();
            Account::debit(money);
        }
        else {
            valid = false;
        }
        return valid;
    }

    // Add money with charge fee
    void CheckingAccount::credit(double money)
    {
        chargeFee();
        Account::credit(money);
    }

    // Display Account information
    ostream& CheckingAccount::display(std::ostream& os)
    {
        os << fixed;
        os.precision(2);
        os << "Account type: Checking" << endl;
        os << "Balance: $ " << getBalance() << endl;
        os << "Transaction Fee: " << transactionFee << endl;
        return os;
    }

}