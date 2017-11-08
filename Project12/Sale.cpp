// Workshop 7 - STL Containers
/*
Filename : Sale.cpp
Student Name: Samantha West
Student Id  : 128111168
Date : 10/30/2017
Description : Store polymorphic products in an STL container using vectors.
While reporting and handling exceptions.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "iProduct.h"
#include "Sale.h"

namespace w7 {

	Sale::Sale(const char* fn) {

		try {
			std::ifstream filename(fn);

			while (filename.good())
			{
				iProduct* ip = readProduct(filename);
				pList.push_back(ip);
			}
		}
		catch (...) {
			std::cout << "Sorry, there was an error opening your file" << std::endl;
		}
		pList.pop_back();
	}

	void Sale::display(std::ostream& os) {

		float sum = 0;

		os << "Product No      Cost Taxable" << std::endl;

		for (auto i : pList)
		{
			os << *i;
			sum += i->getCharge();
		}
		os << std::setw(10) << std::right << "Total " << sum << std::endl;
	}

}
