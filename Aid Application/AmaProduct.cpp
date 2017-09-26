#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AmaProduct.h"

namespace sict {

    AmaProduct::AmaProduct() {
        fileTag_ = 'N';
    }

    // Constructor (receieves char param to store in file tag)
    AmaProduct::AmaProduct(char filetag) {
        (filetag == 'P') ? fileTag_ = filetag : fileTag_ = 'N';
    }

    // Public Member Function (returns constant ptr to the unit_ var)
    const char* AmaProduct::unit() const {
        return unit_;
    }

    // Public Member Function (copies incoming string into unit_ string)
    void AmaProduct::unit(const char* value) {
        strncpy(unit_, value, 11);
        unit_[11] = '\0';
    }

    // fstream << (store) 
    fstream& AmaProduct::store(fstream& file, bool addNewLine) const {
        file << fileTag_ << ","
            << sku() << ","
            << name() << ","
            << price() << ","
            << taxed() << ","
            << quantity() << ","
            << unit_ << ","
            << qtyNeeded();

        if (addNewLine == true) {
            file << "\n";
        }
        return file;
    }

    // fstream >> (load)
    fstream& AmaProduct::load(fstream& file) {
        // assuming record does not have "N" filetag_ starts from sku
        // temp variables to store data "T" represents temporary 
        char skuT[MAX_SKU_LEN];
        char nameT[20];
        double priceT;
        int qtyT;
        char unitT[11];
        int qtyNeededT;
        int taxT;


        file.getline(skuT, MAX_SKU_LEN, ',');
        sku(skuT);

        file.getline(nameT, 20, ',');
        name(nameT);

        file >> priceT;
        price(priceT);
        file.ignore(2000, ',');

        file >> taxT;
        if (taxT == 1) {
            taxed(true);
        }
        else {
            taxed(false);
        }
        file.ignore(2000, ',');

        file >> qtyT;
        quantity(qtyT);
        file.ignore(2000, ',');

        file.getline(unitT, 11, ',');
        unit(unitT);

        file >> qtyNeededT;
        qtyNeeded(qtyNeededT);
        file.ignore(2000, ',');

        return file;
    }

    // ostream (write)
    ostream& AmaProduct::write(ostream& os, bool linear) const {
        bool valid = err_.isClear();
        if (valid == true) {
            if (linear == true) {
                os.setf(std::ios::left);
                os.width(7);
                os << sku() << "|";

                os.width(20);
                os << name() << "|";

                os.setf(std::ios::right);
                os.precision(2);
                os.width(7);
                os.setf(std::ios::fixed);
                os << cost() << "|";

                os.width(4);
                os << quantity() << "|";

                os.unsetf(std::ios::right);
                os.setf(std::ios::left);
                os.width(10);
                os << unit_ << "|";

                os.setf(std::ios::right);
                os.width(4);
                os << qtyNeeded() << "|";
                os.unsetf(std::ios::right);
            }
            else {
                if (taxed() == true) {
                    // liner is false
                    os << "Sku: " << sku() << endl;
                    os << "Name: " << name() << endl;
                    os << "Price: " << price() << endl;
                    os << "Price after tax: " <<
                        price() + (price() * TAX) << endl;
                    os << "Quantity On Hand: " << quantity() << " " << unit_ << endl;
                    os << "Quantity Needed: " << qtyNeeded();
                }
                else {
                    os << "Sku: " << sku() << endl;
                    os << "Name: " << name() << endl;
                    os << "Price: " << price() << endl;
                    os << "Price after tax: " << "N/A" << endl;
                    os << "Quantity On Hand: " << quantity() << " " << unit_ << endl;
                    os << "Quantity Needed: " << qtyNeeded();
                }
            }
        }
        else {
            cout << err_.message();
        }
        return os;
    }

    istream& AmaProduct::read(istream& istr) {
        bool valid = true;
        // if not in fail state function executes 
        if (istr.fail() == false) {
            // while istr is not in fail state, continue to enter data otherwise exit code block
            do {
                err_.clear();
                char skuT[MAX_SKU_LEN];
                cout << "Sku: ";
                istr.getline(skuT, MAX_SKU_LEN, '\n');

                char nameT[20];
                cout << "Name: ";
                istr.getline(nameT, 20, '\n');

                char unitT[11];
                cout << "Unit: ";
                istr.getline(unitT, 11, '\n');
                unit(unitT);

                char taxTemp;
                bool tax;
                cout << "Taxed? (y/n): ";
                istr.get(taxTemp);
                cout.flush();

                if (taxTemp == 'Y' || taxTemp == 'y' ||
                    taxTemp == 'N' || taxTemp == 'n') {
                    if (taxTemp == 'Y' || taxTemp == 'y') {
                        tax = true;
                    }
                    else {
                        tax = false;
                    }
                }
                else {
                    err_.message("Only (Y)es or (N)o are acceptable");
                    valid = false;
                    istr.setstate(std::ios::failbit);
                }

                double priceT;
                if (err_.isClear() == true) {
                    cout << "Price: ";
                }
                istr >> priceT;
                if (istr.fail() && err_.isClear() == true) {
                    err_.message("Invalid Price Entry");
                    valid = false;
                }

                int qtytemp;
                if (err_.isClear() == true) {
                    cout << "Quantity On hand: ";
                }
                istr >> qtytemp;
                if (istr.fail() && err_.isClear() == true) {
                    err_.message("Invalid Quantity Entry");
                    valid = false;
                }

                int qtyNeedTemp;
                if (err_.isClear() == true) {
                    cout << "Quantity Needed: ";
                }
                istr >> qtyNeedTemp;
                if (istr.fail() && err_.isClear() == true) {
                    err_.message("Invalid Quantity Needed Entry");
                    valid = false;
                }

                // set product variables
                if (err_.isClear() == true) {
                    sku(skuT);
                    name(nameT);
                    taxed(tax);
                    price(priceT);
                    quantity(qtytemp);
                    qtyNeeded(qtyNeedTemp);
                    valid = false;
                }
            } while (valid == true);
        }

        return istr;
    }
}

