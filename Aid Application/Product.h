#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_
#include <iostream>
#include "Streamable.h"
#include "general.h"

namespace sict {
    class Product : public Streamable {
        char sku_[MAX_SKU_LEN + 1];
        char *name_;
        double price_;
        bool taxed_;
        int quantity_;
        int qtyNeeded_;
    public:
        // Constructors
        Product();
        Product(const char *sku, const char* name);
        Product(const char sku[], const char *name, bool taxed, double price, int qtyNeeded);
        // Copy Constructor & Copy Assignment operator
        Product(const Product&);
        Product& operator=(const Product&);
        virtual ~Product();
        // Setters
        void sku(char *sku);
        void price(double price) { price_ = price; }
        void name(char *na);
        void taxed(bool tax) { taxed_ = tax; }
        void quantity(int qty) { quantity_ = qty; }
        void qtyNeeded(int qtyNeeded) { qtyNeeded_ = qtyNeeded; }
        // Getters
        const char* sku() const { return sku_; }
        double price() const { return price_; }
        const char* name() const { return name_; }
        bool taxed() const { return taxed_; }
        int quantity() const { return quantity_; }
        int qtyNeeded() const { return qtyNeeded_; }

        double cost() const;
        bool isEmpty() const;
        // Member Operator Overloads
        bool operator==(const char* sku);
        int operator+=(int qty);
        int operator-=(int qty);

    };

    double operator+=(double &d, const Product& src);

    std::ostream& operator<<(std::ostream& os, const Product& P);
    std::istream& operator >> (std::istream& is, Product& P);
}

#endif
