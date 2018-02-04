/* MILESTONE 3: Final Project
Filename: order.cpp
Student: Samantha West 128111168
Date: 12/20/2017
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"

class Order {
	std::string customer, product;
	std::vector<std::string> itemList;
public:
	Order() {}
	Order(std::vector<std::string> line)
	{
		// cout << "Line size = " << line.size() << "\n";

			if (line.size() < 3) {
				throw std::string("expected at least 3 fields");
			}
			else {

				if (validCustomerName(line[0])) {
					customer = line[0];
				}
				else {
					throw std::string("Invalid Customer Name");
				}

				if (validProductname(line[1])) {
					product = line[1];
				}
				else {
					throw std::string("Invalid Product Name");
				}

				for (size_t i = 2; i < line.size(); i++) {
					if (line[i].empty()) // skip null
						continue;
					if (validItemName(line[i])) {
						itemList.push_back(line[i]);
					}
					else {
						throw std::string("Items could not be added to order.");
					}
				}
			}
	}

			
	void print() {
		std::cout << "CUSTOMER ( " << customer << " )\n";
		std::cout << "PRODUCT ( " << product << " )\n";
		std::cout << "ITEM LIST : \n";
			for (auto& order : itemList) {
				std::cout << order << " , ";
			}
			std::cout << "\n\n";
	}

	// dot. -tpng -0 filename,dat,gv
	void graph(std::fstream& gv) {

		for (auto& item : itemList) {
			gv << '"' << customer << "\n" << product << '"' 
				<< "->"
				<< '"' << item << '"'
				<< "[color=blue];\n";
		};
	}
};

class OrderManager {
	std::vector<Order> taskList;
public:
	OrderManager(std::vector<std::vector<std::string>> &csvTaskData)
	{
		
		for (auto& line : csvTaskData)
		{
			try {
				taskList.push_back(Order(line));
			}
			catch (const std::string& e) {
				std::cerr << "Problem is " << e << "\n";
			}
		}
	}

	void print()
	{

		std::cout << "- - - - > ORDERS < - - - - \n";
		for (auto& task : taskList) {
			task.print();
		}
	}

	void graph(std::string& filename)
	{

		std::fstream gv(filename + ".gv", std::ios::in | std::ios::trunc | std::ios::out);

		if (gv.is_open()) {
			gv << "Digraph taskGraph { \n";
			for (auto& task : taskList) {
				task.graph(gv);

			}
			gv << "}\n";
			//gv.close();
		}

		gv.close();

		std::vector<std::string> dotLocations{
			"/usr/bin/dot",                                       // default UNIX
			"/usr/local/bin/dot",                                 // sometimes a UNIX package is installed in /usr/local
			"C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe", // a known DOS location for graphviz 2.38 (current package as of Nov 25, 2017)
			"C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe" // windows double \\ for escape char
		};

		std::string dot;
		for (auto& e : dotLocations) {
			auto fileexist = [](std::string file) {std::fstream f(file, std::ios::in); return f.is_open(); };
			if (fileexist(e)) {
				dot = move(e);
				break;
			}
		}

		if (dot.empty()) {
			std::cerr << "ERROR: Graphviz program not found!  Package is not installed)\n";
		}
		else {
			std::string cmd = dot;
			cmd += " -Tpng -O " + filename; // -O flag - automatically generate the output file name with the proper suffix determined by -T image type flag 
			std::cout << "Running command -->" << cmd << "<--\n";
			int result = system(cmd.c_str());
			std::cout << "It returned '" << result << (result ? "' (command failed)\n" : "' (command passed)\n");
		}
	};

};


int main(int argc, char** argv) {
	
	if (argc != 3) {
		std::cerr << "Not enough arguments to run program, sorry! \n";
		return 1;
	}
	
	std::string filename = argv[1];
	char sep = argv[2][0];
	std::vector<std::vector<std::string>> csvTaskData;

	try {
		csvRead(filename, sep, csvTaskData);
		csvPrint(csvTaskData);

		OrderManager Im(csvTaskData);
		Im.print();
		Im.graph(filename);
	}
	catch (const std::string& e) {
		std::cerr << "Threw an error --> " << e << "\n";
	}

	system("pause");
	return 0;
}
