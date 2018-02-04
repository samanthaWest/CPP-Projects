/* MILESTONE 3: Final Project
Filename: item.cpp
Student: Samantha West 128111168
Date: 12/20/2017
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"

class Item {
	//            0      1         2            3              4
	std::string name, installer, remover, sequenceNumber, description;
public:
	Item(){	}
	Item(std::vector<std::string> line)
	{
		switch (line.size()) {
			//// DESCRIPTION
		case 5:
			description = line[4];
			[[fallthrough]]; // C++ 17
			//// SEQUENCE NUMBER
		case 4:
			if (validSequenceNumber(line[3])) {
				sequenceNumber = line[3];
			} else {
				throw std::string("Sequence Number Not Valid");
			}
			[[fallthrough]]; // C++17
			///// REMOVER
		case 3:
			if (validTaskName(line[2])) {
				remover = line[2];
			} else {
				throw std::string("Task Name Not Valid");
			}
			[[fallthrough]]; // C++17
			//// INSTALLER
		case 2:
			if (validTaskName(line[1])) {
				installer = line[1];
			}
			else {
				throw std::string("Slots not valid");
			}
			[[fallthrough]]; // C++17
			// NAME
		case 1:
			if (validItemName(line[0])) {
				name = line[0];
			}
			else {
				throw std::string("Item Name Not Valid");
			}
			break;
		default:
			throw std::string("Error with task line.. expected 1,2,3,4 fields and found" + line.size());
		}
	}

	void print() {
		std::cout << name << installer << remover << sequenceNumber << description << "\n";
	}

	// dot. -tpng -0 filename,dat,gv
	void graph(std::fstream& gv) {
	
			gv << '"' << "item\n" << name << '"'
				<< "->"
				<< '"' << installer << '"'
				<< "[color=green];" << "\n";
		
			gv << '"' << "item\n" << name << '"'
				<< "->"
				<< '"' << remover << '"'
				<< "[color=red];" << "\n";	
	}
};

class ItemManager {
	std::vector<Item> taskList;
public:
	ItemManager(std::vector<std::vector<std::string>> &csvTaskData)
	{
		for (auto& line : csvTaskData)
		{
			try {
				taskList.push_back(Item(line));
			}
			catch (const std::string& e) {
				std::cerr << "Problem is " << e << "\n";
			}
		}
	}

	void print()
	{
		std::cout << "| NAME | INSTALLER | REMOVER | SEQUENCE NUMBER | DESCRIPTION \n";
		for (auto& task : taskList) {
			task.print();
		}
	}

	void graph(std::string& filename)
	{

		// MAKE GV GRAPH FILE //
		std::fstream gv(filename + ".gv", std::ios::in | std::ios::trunc | std::ios::out);
		//fstream gv("test.txt", ios::in | ios::trunc | ios::out); testing graph output for correct syntax

		if (gv.is_open()) {
			gv << "Digraph taskGraph { \n";
			for (auto& task : taskList) {
				task.graph(gv);
			}
			gv << "}\n";
		}
		gv.close();

		// / / / / / / /  / / / / /

		std::vector<std::string> dotLocations{
			"/usr/bin/dot",                                       // default UNIX
			"/usr/local/bin/dot",                                 // sometimes a UNIX package is installed in /usr/local
			"C:/\"Program Files (x86)\"/Graphviz2.38/bin/dot.exe", // a known DOS location for graphviz 2.38 (current package as of Nov 25, 2017) **
			"C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe" //  For windows, double \\ for escape char
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

			ItemManager Im(csvTaskData);
			Im.print();
			Im.graph(filename);
		}
		catch (const std::string& e) {
			std::cerr << "Threw an error --> " << e << "\n";
		}

		system("pause");
		

		return 0;
	}
