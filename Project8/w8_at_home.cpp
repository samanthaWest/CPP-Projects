// BTP200 Workshop 8: Virtual Functions (HOME)
// File: w8_at_home.cpp
// Date: 2017/07/20th
// Author : Samantha West (128111168)
// Description:
// Base account class, derived savings class and derived checkings class used
// too hold banking information for each person. 
///////////////////////////////////////////////////
#include <iostream>
#include "Account.h" 
#include "SavingsAccount.h" 
#include "CheckingAccount.h" 

using namespace ict;
using namespace std;

int main()
{
	Account * Angelina_Account[2];
 	
	Angelina_Account[ 0 ] = new SavingsAccount( 400.0, 0.12 ); 

	Angelina_Account[ 1 ] = new CheckingAccount( 400.0, 1.0);

	cout << "**************************" << endl;

	cout << "DISPLAY Angelina Accounts:" << endl;

	cout << "**************************" << endl;

	Angelina_Account[0]->display(cout);

	cout << "-----------------------" << endl;

	Angelina_Account[1]->display(cout);

	cout << "**************************" << endl ;

	cout << "DEPOSIT $ 2000 $ into Angelina Accounts ..." << endl ;

	for(int i=0 ; i < 2 ; i++){
		Angelina_Account[i]->credit(2000);
	}

	cout << "WITHDRAW $ 1000 and $ 500 from Angelina Accounts ..." << endl ;

	Angelina_Account[0]->debit(1000);

	Angelina_Account[1]->debit(500);


	cout << "**************************" << endl;

	cout << "DISPLAY Angelina Accounts:" << endl;

	cout << "**************************" << endl;

	Angelina_Account[0]->display(cout);

	cout << "-----------------------" << endl;

	Angelina_Account[1]->display(cout);

	cout << "-----------------------" << endl;

	return 0;
}
