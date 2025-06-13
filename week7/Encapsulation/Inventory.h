#ifndef INVENTORY_H
#define INVENTORY_H
#include "Product.h"

class Inventory {
private:
    std::vector<Product> products;

public:
    void addProduct(const Product& p);
    void removeProduct(int id);
    Product* findProductById(int id);
    Product* findProductByName(const std::string& name);
    void listAllProducts() const;
    void listOutOfStock() const;
    void listLowStock(int threshold) const;
    void updateProduct(int id);
    double totalInventoryValue() const;
};

#endif

