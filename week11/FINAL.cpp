//Though this is more about the coding and less about game design, i thought i'd go over my process

#include<iostream>
using namespace std;
#include <cctype> 
#include <array>
using std::array;
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>


bool bpotion = 25;
bool pickedupArmor = false;
bool pickedupDagger = false;


int main(){
    int playerHP;
    playerHP = 75;
    cout << "-You wake up in a forest\n-You cannot seem to recall anything" << endl;
    cout << "Health: " << playerHP << endl;
    cout << "\n-You spot a dead knight on the ground\nWhat do you do?\n" << endl;
    int choice;
    cout << "1. Loot him\n2. Leave him alone\n";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "\nYou pick up and equip his armor, it's layered with bite marks and scratches.\n" << endl;
      cout << "His sword is cracked and damage and beyond repair, but you find a dagger in his bag." << endl;
      pickedupArmor = true;
      pickedupDagger = true;
      break;
    case 2:
      cout << "\nYou decide to decide to let him rest in peace" << endl;
      pickedupArmor = false;
      pickedupDagger = false;
      break;
  }
  
    cout << "You exit the forest on a path and walk to the gate of a fortified town\n" << endl;
    cout << "A guard wielding a spear yells from a tower:" << endl;
    cout << "'You there! Stop! What's your name?'" << endl;
    std::string playerName;
    cout << "Enter Name: ";
    cin >> playerName;
    cout << "\n'Well..." << playerName << "...I can't say I've heard of you.'" << endl;
    cout << "He seems to be inspecting you, particularly around your neck and arms." << endl;
    if (pickedupArmor == true){
        cout << "'Are you-\nBEHIND YOU!'" << endl;
        cout << "You quickly turn around and jump backwards as you see a man hobble out of the tree line" << endl;
        cout << "His expression is mindless, skin torn and cut, \nand he looks an awful lot like the dead knight..." << endl;
    }
    if (pickedupArmor == false){
        cout << "Are you bit?";
    }
    
    
    
}
