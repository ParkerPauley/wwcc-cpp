#include<iostream>
using namespace std;

double dollarToEuro(int amount); //delcare functions
double dollarToPound(int amount);
double dollarToYen(int amount);

int main(){
    int choice, amount, conversions;
    conversions = 0; //track conversions
    char yn;
        while (true) { //loop to repeat program if user says yes
            
            cout << "CURRENCY CONVERTER\n------------------" << endl; //setting up basic stuff
            cout << "1. Convert USD to Euro (EUR)\n2. Convert USD to British Pound (GBP)\n3. Convert USD to Japanese Yen (JPY)\n4. Exit\n" << endl;
            cout << "\nEnter your choice (1-4): ";
            cin >> choice;
            
            if (choice == 4){
                cout << "Exiting..." << endl;
                
                return 0;
            }
            
            cout << "\nEnter your ammount in USD: ";
            cin >> amount;
            (conversions ++);
    
            if (choice == 1){
                dollarToEuro(amount);
                cout << "Total Conversions: " << conversions << endl;
            }
    
            if (choice == 2){
                dollarToPound(amount);
                cout << "Total Conversions: " << conversions << endl;
            }
    
            if (choice == 3){
                dollarToYen(amount);
                cout << "Total Conversions: " << conversions << endl;
            }
            
            
            
            std::cout << "Do you want to convert again? (y/n): ";
            std::cin >> yn;
            if (yn != 'y') {
                break;
            }
        }
    
    
    
    
    
    
   
    
    return 0;
    
}
//functions
double dollarToEuro(int amount){
    
    cout << amount << " USD = " <<(amount*0.85) << " EUR" << endl;
    
    return 0;
    
}

double dollarToPound(int amount){
    
    cout << amount << " USD = " <<(amount*0.74) << " GBP" << endl;
    
    return 0;
    
}

double dollarToYen(int amount){
    
    cout << amount << " USD = " <<(amount*110.33) << " JPY" << endl;
    
    return 0;
    
}
