#include "util.h"

int main()
{
  int Temp,Unit,C,F,K;
  
  cout << "Temperature Converter\n" << endl;
  
  cout << "Enter temp: ";
  cin >> Temp;
  
  cout << "Choose a number:\n1. Celsius\n2. Fahrenheit\n3. Kelvin\n";
  cin >> Unit;
  
    if (Unit == 1){ //check: is it Celsius? No? then is it Fahrenheit? etc.
        cout << "Celsius: " << Temp << endl;
        cout << "Celsius to Fahrenheit: " << ((Temp*9/5)+32) << endl;
        cout << "Celsius to Kelvin: " << (Temp+273.15) << "\n" << endl;
    }
        else if (Unit == 2) {
            cout << "Fahrenheit: " << Temp << endl;
            cout << "Fahrenheit to Celsius: " << ((Temp-32)*5/9) << endl;
            cout << "Fahrenheit to Kelvin: " << (((Temp-32)*5/9)+273.15) << "\n"  <<  endl;
        }
            else if (Unit == 3) {
            cout << "Kelvin: " << Temp << endl;
            cout << "Kelvin to Celsius: " << (Temp-273.15) << endl;
            cout << "Kelvin to Fahrenheit: " << (((Temp-273.15)*5/9)+32) << "\n"  << endl;
            }
    
    
    //if statements to prevent usage of unaccepted numbers
    if (Unit > 3){ 
        cout << "Error: Num not accepted";
    }
    
    if (Unit < 1){
        cout << "Error: Num not accepted";
    }
    
}
