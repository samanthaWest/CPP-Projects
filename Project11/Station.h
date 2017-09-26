/* Workshop 2: Compound Types
Filename: Station.h
Student: Samantha West (128111168)
Date: 2017/09/15
Description: Station classes store information about monthly passes
monitered by the subway station using fstream and string class.
*/
#pragma once
#include <iostream>

namespace w2 {
    enum PassType { PASS_STUDENT, PASS_ADULT, PASS_COUNT };

    class Station {
        unsigned passes[PASS_COUNT]; // Amount of student/adult passes in current station
        std::string name; // Name of station
    public:
        Station();
        Station(std::fstream&);
        void set(const std::string&, unsigned, unsigned);
        void update(PassType, int);
        unsigned inStock(PassType pt) const { return passes[pt]; }
        const std::string& getName() const { return name; }
        void report();
        void writedata(std::fstream&);
    };
}