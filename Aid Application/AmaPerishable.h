#ifndef SICT_AMA_PERISHABLE_H_
#define SICT_AMA_PERISHABLE_H_
#include "AmaProduct.h"
#include "Date.h"

namespace sict {
    class AmaPerishable : public AmaProduct {
        Date expiry_;
    public:
        AmaPerishable();

        fstream& store(fstream& file, bool addNewLine = true) const;
        fstream& load(fstream& file);

        ostream& write(ostream& ostr, bool linear) const;
        istream& read(istream& istr);
    };
}
#endif
