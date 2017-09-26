#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "AmaPerishable.h"
#include "Date.h"

namespace sict {

    // Constructor receiving 1 param to set to filetag from AmaProduct class
    AmaPerishable::AmaPerishable() : AmaProduct('P') {

    }

    fstream& AmaPerishable::store(fstream& file, bool addNewLine) const {
        AmaProduct::store(file, false);
        file << ",";
        expiry_.write(file);

        if (addNewLine == true) {
            file << "\n";
        }
        return file;
    }

    fstream& AmaPerishable::load(fstream& file) {
        AmaProduct::load(file);
        expiry_.read(file);
        file.ignore();
        return file;
    }

    ostream& AmaPerishable::write(ostream& ostr, bool linear) const {
        AmaProduct::write(ostr, linear);
        if (err_.isClear() == true && isEmpty() != true) {
            if (linear == true) {
                expiry_.write(ostr);
            }
            else {
                ostr << endl;
                ostr << "Expiry date: ";
                expiry_.write(ostr);
            }
        }
        return ostr;
    }

    istream& AmaPerishable::read(istream& istr) {
        AmaProduct::read(istr);
        if (err_.isClear() == true) {
            cout << "Expiry date (YYYY/MM/DD): ";
            Date temp;
            istr >> temp;
            expiry_ = temp;

            if (temp.errCode() == YEAR_ERROR) {
                err_.message("Invalid Year in Date Entry");
                istr.setstate(ios::failbit);
            }
            if (temp.errCode() == MON_ERROR) {
                err_.message("Invalid Month in Date Entry");
                istr.setstate(ios::failbit);
            }
            if (temp.errCode() == CIN_FAILED) {
                err_.message("Invalid Date Entry");
                istr.setstate(ios::failbit);
            }
            if (temp.errCode() == DAY_ERROR) {
                err_.message("Invalid Day in Date Entry");
                istr.setstate(ios::failbit);
            }

        }
        return istr;
    }

}