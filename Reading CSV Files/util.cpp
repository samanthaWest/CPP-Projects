/* MILESTONE 3: Final Project
Filename: util.cpp
Student: Samantha West 128111168
Date: 12/20/2017
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "util.h"

// Trim Spaces
void trimSpace(std::string& s) {
	while (!s.empty() && s[0] == ' ') {
		s.erase(0, 1);
	}
	while (!s.empty() && s[s.size() - 1] == ' ') {
		s.erase(s.size() - 1, 1);
	}
}

// CSVREAD
// if using | use '|' when giving command line arg or it will assume piping
void csvRead(std::string& filename, char sep, std::vector<std::vector<std::string>>& csvData)
{

	std::fstream in(filename, std::ios::in);
	if (!in.is_open()) {
		throw std::string("Cannot be found" + filename);
	}

	std::string line;
	//std::vector<std::string> fields;
	while (getline(in, line)) {

		std::string field;
		std::vector<std::string> fields;

		auto cr = line.find("\r");
		if (cr != std::string::npos) {
			line.erase(cr, 1);
		}

		for (size_t index = 0; index < line.size(); index++) {
			if (line[index] != sep) {
				field += line[index];
			}
			else {
				trimSpace(field);
				if (!field.empty()) {
					fields.push_back(std::move(field));
				}
			}
		}

		if (!fields.empty()) {
			trimSpace(field);
			fields.push_back(field);
			csvData.push_back(std::move(fields));
		}
	}
	in.close();
}

// CVSPRINT
void csvPrint(std::vector<std::vector<std::string>>& csvData)
{
	std::cout << "Range Based for loop: \n";
	for (auto& line : csvData) {
		for (auto&field : line) {
				std::cout << field << " | ";
		}
		std::cout << "\n";
	}
	//std::cout << "\n";

	//cout << "Conventional For Loop \n";
	/*
	for (int line = 0; line < csvData.size(); line++) {
		for (int field = 0; field < csvData[line].size(); field++) {
			std::cout << csvData[line][field] << " | ";
		}
		std::cout << "\n";
	}
	*/

	//cout << "Iterator Loop \n";
	/*
		for (auto line = csvData.begin(); line < csvData.end(); line++) {
		for (auto field = line->begin(); field < line->end(); field++) {
			std::cout << *field << " | ";
		}
		std::cout << "\n";
	}	
	*/
}


// Slots Validation
bool  validSlots(std::string s)
{
	bool valid = true;
	for (auto& c : s)
	{
		if (!isdigit(c)) {
			valid = false;
		}
	}
	return valid;
}

// Name Validation
bool  validTaskName(std::string s)
{
	bool valid = false;
	for (auto c : s) {
		if (isalnum(c) || c != ' ') {
			valid = true;
		}
	}
	return valid;
}

// Sequence Number Validation
bool  validSequenceNumber(std::string s)
{
	bool valid = true;
	for (auto& c : s)
	{
		if (isdigit(c)) {
			valid = false;
		}
	}
	return valid;
}

// Validate Item Name
bool  validItemName(std::string s)
{
	bool valid = true;
	for (auto& c : s)
	{
		if (isdigit(c)) {
			valid = false;
		}
	}
	return valid;
}

// Validate Customer Name
bool validCustomerName(std::string s)
{
	bool valid = true;
	for (auto c : s) {
		if (c == '#') {
			valid = false;
		}
	}
	return valid;
}

// Validate Product Name
bool validProductname(std::string s){

	bool valid = false;
	for (auto c : s) {
		if (isalnum(c)) {
			valid = true;
		}
	}
	return valid;
}
