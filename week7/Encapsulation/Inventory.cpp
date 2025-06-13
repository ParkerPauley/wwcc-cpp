#include "Inventory.h"
#include <iostream>
using namespace std;

void Inventory::addProduct(const Product& p) {
    products.push_back(p);
}

void Inventory::removeProduct(int id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            return;
        }
    }
}

Product* Inventory::findProductById(int id) {
    for (auto& p : products) {
        if (p.getId() == id) return &p;
    }
    return nullptr;
}

Product* Inventory::findProductByName(const string& name) {
    for (auto& p : products) {
        if (p.getName() == name) return &p;
    }
    return nullptr;
}

void Inventory::listAllProducts() const {
    for (const auto& p : products) {
        p.display();
    }
}

void Inventory::listOutOfStock() const {
    for (const auto& p : products) {
        if (p.getQuantity() == 0) p.display();
    }
}

void Inventory::listLowStock(int threshold) const {
    for (const auto& p : products) {
        if (p.getQuantity() < threshold) p.display();
    }
}

void Inventory::updateProduct(int id) {
    Product* p = findProductById(id);
    if (!p) {
        cout << "Product not found." << endl;
        return;
    }
    double newPrice;
    int newQuantity;
    cout << "Enter new price: ";
    cin >> newPrice;
    cout << "Enter new quantity: ";
    cin >> newQuantity;
    p->setPrice(newPrice);
    p->setQuantity(newQuantity);
}

double Inventory::totalInventoryValue() const {
    double total = 0;
    for (const auto& p : products) {
        total += p.getPrice() * p.getQuantity();
    }
    return total;
}

