/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File w2_at_home.cpp
// Version 1.0
// Date May 25th, 2017
// Author Samantha West (128111168)
// Description
// Accepts input into dynamically allocated array Kingdom
// Displays input using overloaded functions
// Adjusts size of dynamically allocated array
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array

	Kingdom* pKingdom = nullptr;

    cout << "==========\n"
        << "Input data\n"
        << "==========\n"
        << "Enter the number of kingdoms: ";
    cin >> count;
    cin.ignore();

    if (count < 1) return 1;

	pKingdom = new Kingdom[count];

    for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);
    }
    cout << "==========" << endl << endl;

    // testing that "display(...)" works
    cout << "------------------------------" << endl
        << "The first kingdom entered is" << endl
        << "------------------------------" << endl;
    display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;

	Kingdom* tmpKingdom = nullptr;
	tmpKingdom = new Kingdom[count+1];

	for (int i = 0; i < count + 1; ++i) {
		tmpKingdom[i] = pKingdom[i];
	}

	delete[] pKingdom;
	pKingdom = tmpKingdom;

    // add the new Kingdom
    cout << "==========\n"
        << "Input data\n"
        << "==========\n"
        << "Kingdom #" << count + 1 << ": " << endl;
	read(pKingdom[count]);
    count++;
    cout << "==========\n" << endl;

	cout << "------------------------------" << endl;
	cout << "Kingdoms of SICT" << endl;
	cout << "------------------------------" << endl;

    // testing that the overload of "display(...)" works
    display(pKingdom, count);
    cout << endl;

	delete[] tmpKingdom;
	tmpKingdom = nullptr;

    return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {

    cout << "Enter the name of the kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}
