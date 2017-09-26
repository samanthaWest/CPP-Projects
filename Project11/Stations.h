/* Workshop 2: Compound Types
Filename: Stations.h
Student: Samantha West (128111168)
Date: 2017/09/15
Description: Station classes store information about monthly passes
monitered by the subway station using fstream and string class.
*/
#pragma once
/* Workshop 2: Compound Types
Filename: Stations.h
Student: Samantha West (128111168)
Date: 2017/09/15
Description: Station classes store information about monthly passes
monitered by the subway station using fstream and string class.
*/
#include <iostream>
#include "Station.h"

// Start of namespace w2
namespace w2 {

    class Stations {
        std::string dataFileName; // Name of file data being read from
        int stationCount; // Size of stationTable 
        Station* stationTable;// Stores instances of type station (e.g Spadina, Bloor etc..)
    public:
        Stations();
        Stations(char*);
        ~Stations();
        void update() const;
        void restock() const;
        void report() const;
    };

}
// End of namespace w2
