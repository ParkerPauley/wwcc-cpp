
//For this assignment, I was having a lot of trouble trying to figure it out so I had to study sources outside of say CodeHs.
//I apologize if the code is similar to said other sources.
//I did my best to re-write and understand each piece of code and I belive I do.



#include "util.h"

int main()
{
  
  char op;
  float val1, val2;
  
    cout << "+, -, *, /: ";
  cin >> op;

  cout << "Enter 2 values: ";
  cin >> val1 >> val2;
    
    
    
 switch(op) {

    case '+':
      cout << val1 << " + " << val2 << " = " << val1 + val2;
      break;

    case '-':
      cout << val1 << " - " << val2 << " = " << val1 - val2;
      break;

    case '*':
      cout << val1 << " * " << val2 << " = " << val1 * val2;
      break;

    case '/':
      cout << val1 << " / " << val2 << " = " << val1 / val2;
      break;
 }
}

