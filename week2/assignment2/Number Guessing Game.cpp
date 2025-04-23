q#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    bool isGuessed;
    
    cout << "Number Guessing Game" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl << endl;
    //For testing: cout << secretNumber << endl;
    while (!isGuessed){
    
        cout << "Enter your guess: ";
        cin >> guess;
        
        if (guess>secretNumber){
            cout << "\nToo high! Try again?\n";
        } else {
            attempts++;
            if (guess<secretNumber){
                cout << "\nToo low! Try again?\n";
            } else {
            attempts++;

            if (secretNumber = guess){;
                cout << "\nCorrect! You win!\n" << endl;
                cout << "Attempts: " << attempts << endl;
                isGuessed = true;
                }
            }
        
        
    }
}
    


    return 0;
}
