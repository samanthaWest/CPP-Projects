/*
Workshop 9 : Smart Pointers
File : Element.h
Name : Samantha West (#128111168)
Date : 11/21/2017
Description -> Merge two lists and use a smart pointer to ensure that memory
is deallocated in the possible handling of an exception. Includes program
component of quadratic complexity and a smart pointer to move an object.
*/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace w9 {

	struct Description {
		unsigned code;
		std::string desc;
		bool load(std::ifstream& f) {
			f >> code >> desc;
			return f.good();
		}
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWD)
				<< desc << std::endl;
		}
	};

	struct Price {
		unsigned code;
		double price;
		bool load(std::ifstream& f) {
			f >> code >> price;
			return f.good();
		}
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product {
		std::string desc;
		double price;
		Product() {}
		Product(const std::string& str, double p) : desc(str), price(p) {}
		void display(std::ostream& os) const {
			os << std::setw(FWD) << desc << std::setw(FWP)
				<< price << std::endl;
		}

		void validate() {
			if (price < 0) { throw "*** Negative Prices are invalid ***"; }
		}
	};
}
