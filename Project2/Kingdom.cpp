/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date May 25th, 2017
// Author Samantha West (128111168)
// Description
// Accepts input into dynamically allocated array Kingdom
// Displays this input using overloaded functions
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

namespace sict {

	// prints object to the screen
	void display(const Kingdom &kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}
	// displays & calculates sum amount of people living in all Kingdoms 
	void display(const Kingdom* kingdom, int pop) {
		int sum = 0;

		if (pop > 0) {
			for (int i = 0; i < pop; ++i) {
				cout << i + 1 << ". ";
				display(kingdom[i]);
				sum += kingdom[i].m_population;
			}
			cout << "------------------------------" << endl;
			cout << "Total population of SICT: " << sum << endl;
			cout << "------------------------------" << endl;
		}
		else {
			cout << "no data availbile" << endl;
		}
	}
}
