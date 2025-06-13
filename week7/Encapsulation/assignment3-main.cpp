#include "Inventory.h"
#include <iostream>
using namespace std;

void menu() {
    cout << "\nInventory Management System\n";
    cout << "1. Add Product\n";
    cout << "2. Display All Products\n";
    cout << "3. Search Product by ID\n";
    cout << "4. Search Product by Name\n";
    cout << "5. Update Product\n";
    cout << "6. Add/Remove Stock\n";
    cout << "7. List Out-of-Stock Products\n";
    cout << "8. List Low-Stock Products\n";
    cout << "9. Total Inventory Value\n";
    cout << "0. Exit\n";
}

int main() {
    Inventory inventory;
    int choice;

    do {
        menu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, quantity;
            double price;
            string name;
            cout << "Enter ID, Name, Price, Quantity: ";
            cin >> id >> name >> price >> quantity;
            inventory.addProduct(Product(id, name, price, quantity));
        } else if (choice == 2) {
            inventory.listAllProducts();
        } else if (choice == 3) {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            Product* p = inventory.findProductById(id);
            if (p) p->display();
            else cout << "Not found.\n";
        } else if (choice == 4) {
            string name;
            cout << "Enter Name: ";
            cin >> name;
            Product* p = inventory.findProductByName(name);
            if (p) p->display();
            else cout << "Not found.\n";
        } else if (choice == 5) {
            int id;
            cout << "Enter ID to update: ";
            cin >> id;
            inventory.updateProduct(id);
        } else if (choice == 6) {
            int id, amount, option;
            cout << "Enter ID: ";
            cin >> id;
            Product* p = inventory.findProductById(id);
            if (!p) {
                cout << "Not found.\n";
                continue;
            }
            cout << "1. Add Stock\n2. Remove Stock\nChoice: ";
            cin >> option;
            cout << "Enter amount: ";
            cin >> amount;
            if (option == 1) p->addStock(amount);
            else if (option == 2) p->removeStock(amount);
        } else if (choice == 7) {
            inventory.listOutOfStock();
        } else if (choice == 8) {
            int threshold;
            cout << "Enter stock threshold: ";
            cin >> threshold;
            inventory.listLowStock(threshold);
        } else if (choice == 9) {
            cout << "Total Inventory Value: $" << inventory.totalInventoryValue() << endl;
        }

    } while (choice != 0);

    return 0;
}

