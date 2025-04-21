#include <iostream>
#include <cmath> //declare use of math functions
#include <iomanip> // declare use of formatting functions
using namespace std;

int main() {
    int startx, starty, endx, endy; //declare each variable

    cout << "Distance Calculator\n" << endl;
    
    cout << "Enter Starting x value: ";
    cin >> startx;
    
    cout << "Enter Starting y value: ";
    cin >> starty;
    
    cout << "Enter Ending x value: ";
    cin >> endx;
    
    cout << "Enter Ending y value: ";
    cin >> endy;
    
    cout << setprecision(3) << "\nThe distance between (" << startx << "," << starty << ") and (" << endx << "," << endy << ") is: " << sqrt(((endx - startx)^2)+((endy-startx)^2)) << endl;
    //equation is the distance formula provided in assignment
    
    
    

    return 0;
}
