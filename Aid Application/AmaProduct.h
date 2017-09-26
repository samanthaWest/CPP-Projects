#ifndef SICT_AMA_PRODUCT_H
#define SICT_AMA_PRODUCT_H
#include "Product.h"
#include "ErrorMessage.h"

namespace sict {
    class AmaProduct : public Product {
        char fileTag_;
        char unit_[11];
    protected:
        ErrorMessage err_;
    public:
        AmaProduct();
        AmaProduct(char filetag);

        const char* unit() const;
        void unit(const char*value);

        fstream& store(fstream& file, bool addNewLine = true) const;
        fstream& load(fstream& file);

        ostream& write(ostream& os, bool linear) const;
        istream& read(istream& istr);
    };
}

#endif