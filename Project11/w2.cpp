/* Workshop 2: Compound Types
   Filename: w2.cpp
   Student: Samantha West (128111168)
   Date: 2017/09/15
   Command Used to compile: g++ -Wall -std=c++0x Stations.cpp Station.cpp w2.cpp -o w2
   Description: Station classes store information about monthly passes
   monitered by the subway station using fstream and string class.
*/
#include <iostream>
#include "Stations.h"
#include "Station.h"

int main(int argc, char* argv[]) {
    std::cout << "\nCommand Line : ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }

    std::cout << std::endl;
    if (argc != 2) {
        std::cerr << "\nIncorrect number of arguments\n";
        return 1;
    }
  
    w2::Stations stations(argv[1]);

    stations.update();
    stations.restock(); 
    stations.report();

    return 0;
}