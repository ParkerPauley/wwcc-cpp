
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <vector>

class Product {
private:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    Product(int id, const std::string& name, double price, int quantity);

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setPrice(double price);
    void setQuantity(int quantity);

    void addStock(int amount);
    void removeStock(int amount);

    void display() const;
};

#endif
