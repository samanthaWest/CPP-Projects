/* Workshop 2: Compound Types
Filename: Stations.cpp
Student: Samantha West (128111168)
Date: 2017/09/15
Description: Station classes store information about monthly passes
monitered by the subway station using fstream and string class.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Stations.h"

// Start of namespace w2
namespace w2 {

    // Stations Class Begins // 
    // Default constructor
    Stations::Stations() {
    }

    // Constructor with one param
    Stations::Stations(char* filename) : dataFileName(filename) {
        std::fstream in(filename, std::ios::in);
        if (!in.is_open()) {
            std::cerr << "Error " << filename << "not opening...\n";
            exit(1);
        }

        // validate initial station count & set, validate delimeter char
        std::string line;
        getline(in, line);

        if (line[1] != ';') {
            std::cerr << "Expected ';' after station cound but found -> " << line[1] << "\n";
            exit(2);
        }

        if (line.size() > 2) {
            std::cerr << "Extra characters after ';' in -> " << line << "n";
            exit(3);
        }

        int countTemp = stoi(line);
        if (countTemp > 0 && isdigit(countTemp) == 0) {
            stationCount = countTemp;
        }

        // Validation done, may proceed
        // Dynamically allocate new memory for array of pointers to objects of type 'Station'
        stationTable = new Station[stationCount];
        for (int i = 0; i < stationCount; i++) {
            stationTable[i] = Station(in); // read from file station name and pass data for every instance
        }
        
       // close file
        in.close();
    }

    // Destructor
    Stations::~Stations() {
        // Write updated data to file before ending program
        std::fstream out(dataFileName, std::ios::out | std::ios::trunc);
        if (out.is_open()) {
            out << stationCount << ";\n";
            for (int i = 0; i < stationCount; i++) {
                stationTable[i].writedata(out);
            }
            out.close();
        }
        delete[] stationTable;
    }

    // Accepts the number of passes sold and updates data for each station in turn
    void Stations::update() const {

        int adultUpdated = 0;
        int studentUpdated = 0;

        std::cout << std::endl;
        std::cout << "Passes Sold : " << std::endl;
        std::cout << "--------------" << std::endl;

        for (int i = 0; i < stationCount; i++) {
            std::cout << stationTable[i].getName() << std::endl;
            std::cout << "Student Passes sold : ";
            std::cin >> studentUpdated;
            std::cout << "Adult Passes sold : ";
            std::cin >> adultUpdated;

            if (isdigit(adultUpdated) == 0 && isdigit(studentUpdated) == 0) {
                stationTable[i].update(PASS_STUDENT, (0 - studentUpdated));
                stationTable[i].update(PASS_ADULT, (0 - adultUpdated));
            }
            else {
                std::cerr << "Input inccorrect, must be a digit" << std::endl;
			exit(5);
            }
        }
    }

    // Accepts the number off passes added and updates the data for each station in turn
    void Stations::restock() const {

        int adultUpdated = 0;
        int studentUpdated = 0;

        std::cout << std::endl;
        std::cout << "Passes Sold : " << std::endl;
        std::cout << "--------------" << std::endl;
        for (int i = 0; i < stationCount; i++) {
            std::cout << stationTable[i].getName() << std::endl;
            std::cout << "Student Passes added : ";
            std::cin >> studentUpdated;
            std::cout << "Adult Passes added : ";
            std::cin >> adultUpdated;

            if (isdigit(adultUpdated) == 0 && isdigit(studentUpdated) == 0) {
                stationTable[i].update(PASS_STUDENT, studentUpdated);
                stationTable[i].update(PASS_ADULT, adultUpdated);
            }
            else {
                std::cerr << "Input inccorrect, must be a digit" << std::endl;
			exit(6);
              }
        }
    }

    // Reports the number of passes currently availible at each station
    void Stations::report() const {
        std::cout << std::endl;
        std::cout << "Passes in Stock : Student Adult" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        for (int i = 0; i < stationCount; i++) {
            stationTable[i].report();
        }
    }

    //Stations Class Ends //
}
// End of namespace w2