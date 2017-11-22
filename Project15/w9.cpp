/*
Workshop 9 : Smart Pointers 
File : w9.cpp
Name : Samantha West (#128111168)
Date : 11/21/2017
Description -> Merge two lists and use a smart pointer to ensure that memory
is deallocated in the possible handling of an exception. Includes program
component of quadratic complexity and a smart pointer to move an object.
*/
#include <iostream>
#include <iomanip>
#include <memory>
#include "Element.h"
#include "List.h"

const int FWC = 5;
const int FWD = 12;
const int FWP = 8;

w9::List<w9::Product> merge(const w9::List<w9::Description>& desc,
	const w9::List<w9::Price>& price) {
	w9::List<w9::Product> priceList;

	for (int i = 0; i < price.size(); i++) {
		for (int j = 0; j < desc.size(); j++) {
			if (price[i].code == desc[j].code) {
				std::unique_ptr<w9::Product> p(new w9::Product(desc[j].desc, price[i].price));
				priceList += std::ref(p);
				p->validate(); // validate stored product 	
			}
		}
	}

	return priceList;
}

int main(int argc, char** argv) {
	
	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 3) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	
	try {
		w9::List<w9::Description> desc(argv[1]);
		//w9::List<w9::Description> desc("Descriptions.txt"); testing
		std::cout << std::endl;
		std::cout << std::setw(FWC) << "Code" <<
			std::setw(FWD) << "Description" << std::endl;
		std::cout << desc << std::endl;
		w9::List<w9::Price> price(argv[2]);
		// w9::List<w9::Price> price("Prices.txt"); testing
		// w9::List<w9::Price> price("BadPrices.txt"); testing
		std::cout << std::endl;
		std::cout << std::setw(FWC) << "Code" <<
			std::setw(FWP) << "Price" << std::endl;
		std::cout << price << std::endl;
		w9::List<w9::Product> priceList = merge(desc, price);
		std::cout << std::endl;
		std::cout << std::setw(FWD) << "Description" <<
			std::setw(FWP) << "Price" << std::endl;
		std::cout << priceList << std::endl;
	}
	catch (const std::string& msg) {
		std::cerr << msg << std::endl;
	}
	catch (const char* msg) {
		std::cerr << msg << std::endl;
	}

	std::cout << "\nPress any key to continue ... ";
	std::cin.get();
}