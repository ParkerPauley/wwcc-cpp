#include <iostream>
#include <sstream>
#include <string> 
#include <cctype>
#include <iomanip> // declare use of formatting functions
using namespace std;

int main() {
    
    std::string formatWithCommas(long long number); //declare format
    
    cout << "Print Formatting\n" << endl;
    
    cout <<"Integer Formatting\n";
    cout << "Original: 1234567" << endl;
    
    std::cout << "Formatted: " <<formatWithCommas(1234567) << endl;
    
    cout <<"\nDouble Formatting\n";
    cout <<"Original: 45.6789" << endl;
    
    float n = 45.6789;

    std::cout << "Formatted: " << std::fixed << std::setprecision(2) << n << std::endl; //precision function/cout
    
    cout <<"\nDouble Formatting w/ custom amount (3)\n";
    
    cout <<"Original: 45.6789" << endl;
    float a = 45.6789;
    
    std::cout << "Formatted: " << std::fixed << std::setprecision(3) << a << std::endl;
    
    cout << "\nString Formatting \n";
    cout <<"Original: hello world of c++ programming!\n";
    string str ="hello world of c++ programming!";
    int i;
    for (i=0;i<str.length(); i++) //loop to determine & place capitalizations
    {
        if (i==0)
        {
            str[i]=toupper(str[i]);
        }
        
        else if(str [i-1]==' ')
        {
            str [i]=toupper(str[i]);

        }
    }
    
    cout<<"Formatted: "<<str;
    


    
    

    return 0;
}

std::string formatWithCommas(long long number) //loop to determine where/when commas go
    {
    std::string number_str = std::to_string(number);

    for (int i = number_str.length() - 3; i > 0; i -= 3)
        number_str.insert(i, ",");

    return number_str;
}
