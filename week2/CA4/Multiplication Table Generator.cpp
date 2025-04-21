#include <iostream>
#include <iomanip>  // For setw function
using namespace std;

int main() {
    int start, end;

    cout << "Multiplication Table Generator" << endl << endl;

    cout << "Enter starting number: ";
    cin >> start;

    cout << "Enter ending number: ";
    cin >> end;

    // Validate input
    if (start > end) {
        cout << "Error: Starting number must be less than ending number." << endl;
        return 1;
    }

    cout << endl;

    for (int i = start; i <= end; i++) {
    
    for (int j = start; j <= end; j++) {
      std::cout << "\t" << i * j <<"|";
    }
    std::cout << std::endl;
}

    return 0;
}
