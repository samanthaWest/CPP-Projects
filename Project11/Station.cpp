/* Workshop 2: Compound Types
Filename:Station.cpp
Student: Samantha West (128111168)
Date: 2017/09/15
Description: Station classes store information about monthly passes
monitered by the subway station using fstream and string class.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Station.h"

namespace w2 {
    // Station Class Starts

    // Default constructor
    Station::Station() {
    }

    // Constructor to read data from file and set
    Station::Station(std::fstream& in) {
        // hold data read starting at second line from opened file
        int index = 0;
        std::string line;
        std::string n;
        std::string passAdult;
        std::string passStudent;

        // read line
        getline(in, line);

        // seperate station name
        while (line[index] != ';') {
            n += line[index];
            index++;
        }

        index++; // skip semi colon in array
                 // seperate student pass count 
        int delimeter = line.find(" ");
        for (int i = 0; index < delimeter; i++) {
            passStudent += line[index];
            index++;

        }

        index++; // skip whitespace
                 // seperate adult pass count
        while ((unsigned)index < line.size()) {
            passAdult += line[index];
            index++;
        }

        // Convert from string to digits
        int s = stoi(passStudent);
        int a = stoi(passAdult);

        // set(name, adult, student);
        set(n, s, a);

    }

    // Updates the number of passes sold or restocked
    void Station::update(PassType p, int c) {
        if (c > 0) {
            passes[p] -= c;
        }
        else {
            passes[p] += c;
        }
    }

    // Set station name and passes
    void Station::set(const std::string& n, unsigned s, unsigned a) {
        name = n;
        passes[PASS_STUDENT] = s;
        passes[PASS_ADULT] = a;
    }

    // Print report
    void Station::report() {
        std::cout << std::left << std::setw(20) << name
            << std::setw(6) << passes[PASS_STUDENT]
            << std::setw(6) << passes[PASS_ADULT];
        std::cout << std::endl;
    }

    // Write data to file
    void Station::writedata(std::fstream& out) {
        out << getName() << ";" << inStock(PASS_STUDENT) << " " <<
            inStock(PASS_ADULT) << "\n";
    }

    // Station Class Ends //
}