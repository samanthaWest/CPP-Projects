/* Milestone 5: AMAPRODUCT & AMAPERISHABLE CLASSES
Student: Samantha West (128111168)
Filename: Product.cpp
Date: 2017/07/20
Description: Aid management releif app.
//////////////////////////////////////////////
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Product.h"
#include "Streamable.h"
#include "general.h"

namespace sict {

    // Default constructor
    Product::Product() {
        sku_[0] = '\0';
        name_ = nullptr;
        price_ = 0;
        quantity_ = 0;
        qtyNeeded_ = 0;
    }

    // 2 argument constructor
    Product::Product(const char *sku, const char* na) {
        price_ = 0;
        quantity_ = 0;
        qtyNeeded_ = 0;
        if (name_ != nullptr && sku != nullptr) {

            strncpy(sku_, sku, MAX_SKU_LEN + 1);
            sku_[MAX_SKU_LEN] = '\0';

            int newSize = strlen(na);
            name_ = new char[newSize];
            strncpy(name_, na, newSize);
            name_[newSize] = '\0';
        }
    }

    // 5 argument constructor
    Product::Product(const char sku[], const char *na, bool taxed, double price, int qtyNeeded) {

        // Allocates memory for new name & copies sku
        if (name_ != nullptr && sku != nullptr) {

            strncpy(sku_, sku, MAX_SKU_LEN + 1);
            sku_[MAX_SKU_LEN] = '\0';

            int newSize = strlen(na);
            name_ = new char[newSize];
            strncpy(name_, na, newSize);
            name_[newSize] = '\0';

        }

        // Set other variables
        quantity_ = 0;
        qtyNeeded_ = qtyNeeded;
        price_ = price;

        // Set taxed status
        if (taxed == true || taxed == false) {
            taxed_ = taxed;
        }
        else {
            taxed_ = true;
        }
    }

    // Copy constructor
    Product::Product(const Product& src) {
        qtyNeeded_ = src.qtyNeeded_;
        quantity_ = src.quantity_;
        taxed_ = src.taxed_;
        price_ = src.price_;
        if (src.name_ != nullptr && src.sku_ != nullptr) {
            strncpy(sku_, src.sku_, MAX_SKU_LEN + 1);
            sku_[MAX_SKU_LEN] = '\0';
            int newSize = strlen(src.name_);
            name_ = new char[newSize];
            strncpy(name_, src.name_, newSize);
            name_[newSize] = '\0';

        }

    }

    // Copy assignment operator 
    Product& Product::operator=(const Product& src) {

        if (this != &src) {
            qtyNeeded_ = src.qtyNeeded_;
            quantity_ = src.quantity_;
            taxed_ = src.taxed_;
            price_ = src.price_;

            if (src.sku_ != nullptr && src.name_ != nullptr) {
                strncpy(sku_, src.sku_, MAX_SKU_LEN + 1);
                sku_[MAX_SKU_LEN] = '\0';

                delete[] name_;

                int newSize = strlen(src.name_);
                name_ = new char[newSize];
                strncpy(name_, src.name_, newSize);
                name_[newSize] = '\0';
            }

        }
        return *this;
    }

    // virtual destructor 
    Product::~Product() {
        name_ = nullptr;
        delete[] name_;
        name_ = nullptr;
    }

    // get sku
    void Product::sku(char *sku) {
        strncpy(sku_, sku, MAX_SKU_LEN + 1);
        sku_[MAX_SKU_LEN] = '\0';
    }

    // get name
    void Product::name(char* na) {
        int newSize = strlen(na);
        name_ = new char[newSize];
        strncpy(name_, na, newSize);
        name_[newSize] = '\0';
    }

    // return cost if taxed or without
    double Product::cost() const {
        double total;

        if (taxed() == true) {
            total = price_ + (price_ * TAX);
        }
        else {
            total = price_;
        }
        return total;
    }

    // return state of class
    bool Product::isEmpty() const {
        bool valid = false;
        if (sku_[0] == '\0' && quantity_ == 0 && name_ == nullptr && qtyNeeded_ == 0) {
            valid = true;
        }

        return valid;
    }

    // compare sku's
    bool Product::operator==(const char* sku) {
        bool valid = false;
        if (strcmp(sku_, sku) == 0) {
            valid = true;
        }

        return valid;
    }

    // adds quantity to product
    int Product::operator+=(int qty) {
        quantity_ = quantity_ + qty;
        return quantity_;
    }

    // subtracts quantity from product
    int Product::operator-=(int qty) {
        quantity_ -= qty;
        return quantity_;
    }

    // adds total cost of and returns double
    double operator+=(double &d, const Product& src) {
        d += (src.cost() * src.quantity());
        return d;
    }

    // overloaded output operator
    std::ostream& operator<<(std::ostream& os, const Product& P) {
        P.write(os, true);
        return os;
    }

    // overloaded input operator
    std::istream& operator >> (std::istream& is, Product& P) {
        P.read(is);
        return is;
    }

}
