// Workshop 7 - STL Containers
/*
Filename : iProduct.h
Student Name: Samantha West
Student Id  : 128111168
Date : 10/30/2017
Description : Store polymorphic products in an STL container using vectors.
While reporting and handling exceptions.
*/
#pragma once
#include <iostream>
#include <fstream>

namespace w7 {

	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	class Product : public iProduct {
		int id;
		double price;
	public:
		Product(int, double);
		double getCharge() const;
		void display(std::ostream& ) const;
	};

	class TaxableProduct :public iProduct {
		int id;
		double price;
		char tax;
	public:
		TaxableProduct(int, double, char);
		double getCharge() const;
		void display(std::ostream&) const;
	};


	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);

}

