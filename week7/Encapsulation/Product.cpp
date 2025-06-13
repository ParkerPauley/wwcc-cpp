#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(int id, const string& name, double price, int quantity)
    : id(id), name(name), price(price), quantity(quantity) {}

int Product::getId() const { return id; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getQuantity() const { return quantity; }

void Product::setPrice(double p) {
    if (p >= 0) price = p;
}

void Product::setQuantity(int q) {
    if (q >= 0) quantity = q;
}

void Product::addStock(int amount) {
    if (amount > 0) quantity += amount;
}

void Product::removeStock(int amount) {
    if (amount > 0 && amount <= quantity) quantity -= amount;
}

void Product::display() const {
    cout << "ID: " << id << ", Name: " << name << ", Price: $" << price
         << ", Quantity: " << quantity << endl;
}

