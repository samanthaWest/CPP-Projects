/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

namespace sict {

	struct Kingdom {
		char m_name[32];
		int m_population;
	};
	void display(const Kingdom&);
	void display(const Kingdom*, int);
}
#endif 

