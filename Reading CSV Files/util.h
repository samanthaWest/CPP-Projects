/* MILESTONE 3: Final Project
Filename: util.h
Student: Samantha West 128111168
Date: 12/20/2017
*/
#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//Remove Spaces
void trimSpace(std::string& s);

// CSVREAD
void csvRead(std::string& filename, char sep, std::vector<std::vector<std::string>>& csvData);

// CVSPRINT
void csvPrint(std::vector<std::vector<std::string>>& csvData);

// Slot Validation
bool  validSlots(std::string);

// Name Validation
bool  validTaskName(std::string);

// Sequence Number Validation
bool  validSequenceNumber(std::string);

// Name Validation
bool  validItemName(std::string);

// Customer Name Validation
bool validCustomerName(std::string);

// Product Name Validation
bool validProductname(std::string);