/* Milestone 5: AMAPRODUCT & AMAPERISHABLE CLASSES
Student: Samantha West (128111168)
Filename: streamable.h
Date: 2017/07/20
Description: Aid management releif app.
//////////////////////////////////////////////
*/
#ifndef SICT_STREAMABLE_H_
#define SICT_STREAMABLE_H_
#include <iostream>
#include <fstream>

namespace sict {
    class Streamable {
    public:
        virtual std::fstream& store(std::fstream& file, bool addNewLine = true) const { return file; }
        virtual std::fstream& load(std::fstream& file) { return file; }
        virtual std::ostream& write(std::ostream& os, bool linear) const { return os; }
        virtual std::istream& read(std::istream& is) { return is; }
    };
}
#endif