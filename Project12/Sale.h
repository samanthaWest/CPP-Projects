// Workshop 7 - STL Containers
/*
Filename : Sale.h
Student Name: Samantha West
Student Id  : 128111168
Date : 10/30/2017
Description : Store polymorphic products in an STL container using vectors.
While reporting and handling exceptions.
*/
#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "iProduct.h"

namespace w7 {

	class Sale {
		std::vector<iProduct*> pList;
	public:
		Sale(const char*);
		void display(std::ostream&);
	};
}
