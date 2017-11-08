// Workshop 7 - STL Containers
/*
Filename : iProduct.cpp
Student Name: Samantha West
Student Id  : 128111168
Date : 10/30/2017
Description : Store polymorphic products in an STL container using vectors.
While reporting and handling exceptions.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "iProduct.h"

namespace w7 {

	// Product Begins

	// 2 Argument Constructor
	Product::Product(int newId, double newPrice)
	{
		if (newId > 0 && newPrice > 0) {
			id = newId;
			price = newPrice;
		}
		else {
			std::cerr << "File input corrupt, can't read";
			exit(1);
		}
	}

	// Price query
	double Product::getCharge() const {
		return price;
	}

	// Display product " << "
	void Product::display(std::ostream& os) const
	{
		os << std::setw(10) << std::right;
		os << id;
		os << std::setw(10) << std::right;
		os << price << std::endl;
	}

	// Product Ends

	// Taxable product beings

	// Taxable Product Constructor
	TaxableProduct::TaxableProduct(int newId, double newPrice, char t)
	{
		if (newId > 0 && newPrice > 0) {
			id = newId;
			price = newPrice;
			tax = t;
		}
		else {
			std::cerr << "File input corrupt, can't read";
			exit(2);
		}
	}

	double TaxableProduct::getCharge() const
	{
		double t = 0;
		// GST 13% .. PST 8%
		tax == 'H' ? t = 1.13 : t = 1.08;
		return price*t;
	}

	void TaxableProduct::display(std::ostream& os) const
	{
		os << std::setw(10) << std::right;
		os << id;
		os << std::setw(10) << std::right;
		os << price << "  ";
		if (tax == 'H')
		{
			os << "HST";
		} 
		if (tax == 'P')
		{
			os << "PST";
		}
		os << std::endl;
	}
	// Taxable product ends

	// Helper Functions

	std::ostream& operator<<(std::ostream& os, const iProduct& p)
	{
		p.display(os);
		return os;
	}

	iProduct* readProduct(std::ifstream& is)
	{
		int i;
		double p;
		char t;
		iProduct* temp;

		is >> i >> p;

		if (is.get() != '\n')
		{
			is.get(t);
			temp = new TaxableProduct(i, p, t);
		}
		else {
			temp = new Product(i, p);
		}
		return temp;
	}
	// End of Helper Functions

}