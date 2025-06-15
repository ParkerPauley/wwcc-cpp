//Though this is more about the coding and less about game design, i thought i'd go over my process
//I wanted each choice to have some kind of impact, but that impact needs to be felt
//The first example is the choice to pick up armor, if you do, you get extra protection, but it frees up the zombie to move and attack you

#include<iostream>
using namespace std;
#include <cctype> 
#include <array>
using std::array;
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
bool isInCombat = false;
int numOfEnemies;
bool isAlive = true;
void enterCombat(bool pickedupArmor, bool pickedupDagger, int playerHP, bool isInCombat, std::string enemyname, int enemyhp, int enemyamount, int enemydamage, int fistDamage, int daggerDamage, int potion, bool hasPotion);

void enemyAttack(bool pickedupArmor, int playerHP, std::string enemyname, int enemydamage, int enemyhp);


int fistDamage = 15;
int daggerDamage = 25;
int potion = 25;
bool hasPotion = false;
bool pickedupArmor = false;
bool pickedupDagger = false;
int playerHP = 100;
bool finishedConvo = false;

int main(){
    playerHP = 75;
    cout << "-You wake up in a forest\n-You cannot seem to recall anything" << endl;
    cout << "\n-You spot a dead knight on the ground\n-What do you do?\n" << endl;
    int choice;
    cout << "1. Loot him\n2. Leave him alone\n";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "\n-You pick up and equip his armor, it's layered with bite marks and scratches.\n-The armor increases your max HP by 25 points\n" << endl;
      playerHP+=25;
      cout << "Current HP: " << playerHP << endl;
      cout << "\n-His sword is cracked and damage and beyond repair, but you find a dagger in his bag." << endl;
      pickedupArmor = true;
      pickedupDagger = true;
      
      break;
    case 2:
      cout << "\n-You decide to decide to let him rest in peace" << endl;
      pickedupArmor = false;
      pickedupDagger = false;
      break;
  }
  
    cout << "\n-You exit the forest on a path and walk to the gate of a fortified town\n" << endl;
    cout << "-A guard wielding a spear yells from a tower:" << endl;
    cout << "'You there! Stop! What's your name?'" << endl;
    std::string playerName;
    cout << "=======Enter Name:=======\n";
    cin >> playerName;
    cout << "\n'Well..." << playerName << "...I can't say I've heard of you.'" << endl;
    cout << "\n-He seems to be inspecting you, particularly around your neck and arms." << endl;
    if (pickedupArmor == true){
        cout << "'Are you-\nBEHIND YOU!'" << endl;
        cout << "\n-You quickly turn around and jump backwards as you see a man hobble out of the tree line" << endl;
        cout << "-His expression is mindless, skin torn and cut, \n and he looks an awful lot like the dead knight..." << endl;
        std::string enemyname = "Undead Knight";
        int enemyhp = 60;
        int enemyamount = 1;
        int enemydamage = 20;
        enterCombat(pickedupArmor, pickedupDagger,playerHP, isInCombat, enemyname, enemyhp, enemyamount, enemydamage, fistDamage, daggerDamage, potion, hasPotion);
        cout << "'Glad that's over, now as I was saying'" << endl;
    }
    cout << "'Are you bit?'\n" << endl;
    cout << "1. 'No'\n2.'Yes'" << endl;
    cin >> choice;
    if (choice == 2){
        cout << "-The guard throws his spear at you, killing you instantly." << endl;
        cout << "\nYou died!\n======GAME OVER=====" << endl;
        return 0;
    }
    cout << "-He looks weary at first, be decides to trust you" << endl;
    cout << "'Alright, I'll open the gate up, but if you're lying it'll be a quick death'" << endl;
    cout << "\n-You step through the gates, it's a small but fortified town\n-Guards roam the streets as scavengers and survivors try to sell what they can" << endl;
    cout << "\n'Look, we don't normally let people in, but the fact that I don't know you is why you may be useful'" << endl;
    
    while (finishedConvo = false){
        cout << "1. 'Why did that guy attack me? And why did he look like that?'\n2.'And if I don't want to help?'\n3. 'Okay, I'll help'\n";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "'You playing dumb or do you reall not know?" << endl;
            cout << "'I guess you might not, long story short but the dead don't stay dead anymore'" << endl;
            cout << "'Make no mistake, they're not people, they don't think, they only attack and eat'" << endl;
            cout << "'Nobody is sure how or why it happened, personally I blame those Godless mathematicians'" << endl;
        
        case 2:
            cout << "'Then I'll kick you out and you'll figure things out on your own" << endl;
        case 3:
            cout << "'Amazing'" << endl;
            finishedConvo = true;
        }
    finishedConvo = false;
    }
}

void enterCombat(bool pickedupArmor, bool pickedupDagger, int playerHP, bool isInCombat, std::string enemyname, int enemyhp, int enemyamount, int enemydamage, int fistDamage, int daggerDamage, int potion, bool hasPotion){
    isInCombat = true;
    cout << "\nEntering Combat...\n";
    cout << "Current HP: " << playerHP << endl;
    if (pickedupArmor == true){
        cout << "Armor is equipped" << endl;
    }
    if (pickedupArmor == false){
        cout << "Armor is not equipped" << endl;
    }
    if (enemyamount == 1){
        cout << "\nYou are facing off against " << enemyamount << " " << enemyname << endl;
    }
    if (enemyamount > 1){
        cout << "\nYou are facing off against " << enemyamount << " " << enemyname << "s" << endl;
        enemyhp*=enemyamount;
    }
    cout << "Enemy HP: " << enemyhp << endl;
    while (enemyhp > 0){
        if (playerHP <= 0){
            cout << "You died!\n======GAME OVER=====" << endl;
        }
        cout << "What do you do?" << endl;
        int combatChoice;
        cout << "1. Attack\n2. Heal\n3. Skip turn\n";
        cin >> combatChoice;
        switch (combatChoice){
            case 1:
                if (pickedupDagger == true){
                    cout << "\n-You attack the enemy with your dagger, dealing 25 damage" << endl;
                    enemyhp-=daggerDamage;
                    cout << "Enemy HP: " << enemyhp << endl;
                    enemyAttack(pickedupArmor, playerHP, enemyname, enemydamage, enemyhp);
                }
                if (pickedupDagger == false){
                    cout << "\n-You attack the enemy with your fists, dealing 15 damage" << endl;
                    enemyhp-=fistDamage;
                    cout << "Enemy HP: " << enemyhp << endl;
                    enemyAttack(pickedupArmor, playerHP, enemyname, enemydamage, enemyhp);
                }
                break;
            case 2:
                if (hasPotion == true){
                    cout << "You drink your health potion" << endl;
                    playerHP = playerHP+=potion;
                    hasPotion = false;
                    cout << "Current HP: " << playerHP << endl;
                    enemyAttack(pickedupArmor, playerHP, enemyname, enemydamage, enemyhp);
                }
                if (hasPotion == false){
                    cout << "You don't have a health potion!" << endl;
                    cout << "Current HP: " << playerHP << endl;
                    enemyAttack(pickedupArmor, playerHP, enemyname, enemydamage, enemyhp);
                }
                break;
            case 3:
                cout << "Skipping turn..." << endl;
                enemyAttack(pickedupArmor, playerHP, enemyname, enemydamage, enemyhp);
                break;
        }
    
    }
    cout << "-You won!\n" << endl;
}

void enemyAttack(bool pickedupArmor, int playerHP, std::string enemyname, int enemydamage, int enemyhp){
    cout << "The " << enemyname << " hits you for " << enemydamage << " points of damage!" << endl;
    playerHP-=enemydamage;
    cout << "\nCurrent HP: " << playerHP << endl;

}

