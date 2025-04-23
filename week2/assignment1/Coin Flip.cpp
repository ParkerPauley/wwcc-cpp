#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

int main() {
    
    srand(time(0));

    int flips;
    int heads = 0;
    int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;

    cout << "\nFlipping " << flips << " coin(s)... \n" << endl;
    cout << "Results: \n" <<endl;
    int randomNum1 = rand() % (flips+1);
    
    int randomNum2 = (flips-randomNum1);
    
    cout << "Heads: " << randomNum1 << "     (" <<  randomNum1 << "%)" << endl;
    cout << "Tails: " << randomNum2 << "     (" <<  randomNum2 << "%)"  << endl;

    return 0;
}
