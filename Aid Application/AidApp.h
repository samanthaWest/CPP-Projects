#ifndef SICT_AID_APP_H
#define SICT_AID_APP_H
#include "AmaPerishable.h"

namespace sict {

    class AidApp : public AmaPerishable {
        char filename_[256]; // HOLDS NAME OF TEXT FILE 
        Product* product_[MAX_NO_RECS]; // ARRAY OF PTRS TO EACH ELEMENT E.G PRODUCT
        fstream datafile_; // FSTREAM INSTANCE USED TO CREATE AND ACCESS FILE
        int noOfProducts_; // NUMBER OF PRODUCTS PERISHABLE & NOT PTR TO BY PRODUCT ARRAY
    public:
        // Constructor
        AidApp(const char* filename);
        // Copy and Assignment prevention using delete decleration
        AidApp(const AidApp&) = delete;
        AidApp& operator=(const AidApp&) = delete;

        // Pause function
        void pause() const;
        // Menu
        int menu();
        // Load Recs
        void loadRecs();
        // Save Recs
        void saveRecs();
        // Listing of products
        void listProducts() const;
        // Search for product
        int SearchProducts(const char* sku) const;
        // Update quantity
        void addQty(const char*sku);
        // Add product
        void addProduct(bool isPerishable);
        // Run 
        int run();
    };
}
#endif