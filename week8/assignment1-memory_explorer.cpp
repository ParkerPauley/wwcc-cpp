#include <iostream>
using namespace std;


void modifyByReference(int& a, double& b, char& c) {
    a += 10;
    b *= 2.5;
    c = toupper(c);
    cout << "[Inside modifyByReference] Modified values:\n";
    cout << "  int: " << a << ", address: " << &a << '\n';
    cout << "  double: " << b << ", address: " << &b << '\n';
    cout << "  char: " << c << ", address: " << static_cast<void*>(&c) << '\n';
}


void modifyByPointer(int* a, double* b, char* c) {
    if (a) *a += 5;
    if (b) *b /= 2.0;
    if (c) *c = tolower(*c);

    cout << "[Inside modifyByPointer] Modified values:\n";
    if (a) cout << "  int: " << *a << ", address: " << a << '\n';
    if (b) cout << "  double: " << *b << ", address: " << b << '\n';
    if (c) cout << "  char: " << *c << ", address: " << static_cast<void*>(c) << '\n';
}

void exploreArrayAndPointers() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    cout << "\n[Array and Pointer Exploration]\n";
    cout << "Array base address (arr): " << arr << "\n";

    for (int i = 0; i < 5; ++i) {
        cout << "  arr[" << i << "] = " << arr[i]
             << ", *(ptr + " << i << ") = " << *(ptr + i)
             << ", &arr[" << i << "] = " << &arr[i] << '\n';
    }
}

int main() {
 
    int i = 42;
    double d = 3.14;
    char c = 'x';

    cout << "=== Memory Explorer ===\n";
    cout << "[Initial Values and Addresses]\n";
    cout << "int:    " << i << " at " << &i << '\n';
    cout << "double: " << d << " at " << &d << '\n';
    cout << "char:   " << c << " at " << static_cast<void*>(&c) << '\n';


    cout << "\n[Modifying using References]\n";
    modifyByReference(i, d, c);
    cout << "[After modifyByReference]\n";
    cout << "int: " << i << ", double: " << d << ", char: " << c << '\n';


    cout << "\n[Modifying using Pointers]\n";
    modifyByPointer(&i, &d, &c);
    cout << "[After modifyByPointer]\n";
    cout << "int: " << i << ", double: " << d << ", char: " << c << '\n';


    cout << "\n[Null Pointer Check]\n";
    int* nullIntPtr = nullptr;
    modifyByPointer(nullIntPtr, &d, &c);

    exploreArrayAndPointers();

    return 0;
}
