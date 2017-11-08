// Workshop 7 - STL Containers
/*
Filename : w7.cpp
Student Name: Samantha West
Student Id  : 128111168
Date : 10/30/2017
Description : Store polymorphic products in an STL container using vectors.
While reporting and handling exceptions.
*/
#include <iostream>
#include <string>
#include "Sale.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << argv[0] << ": incorrect number of arguments\n";
		std::cerr << "Usage: " << argv[0] << " file_name\n";
		return 1;
	}

	w7::Sale sale(argv[1]);
	// testing ... w7::Sale sale("Sales.txt");
	sale.display(std::cout);

	std::cout << "\nPress any key to continue ... ";
	std::cin.get();

	// system("pause");
}