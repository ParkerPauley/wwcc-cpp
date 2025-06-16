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
#include <cstdlib>


bool isInCombat = false;
int numOfEnemies;
bool isAlive = true;
void enterCombat(bool pickedupArmor, bool pickedupDagger, int playerHP, bool isInCombat, std::string name, int HP, int amount, int damage, int fistDamage, int daggerDamage, int potion, bool hasPotion);
void clearScreen();
void enemyAttack(bool pickedupArmor, int playerHP, std::string name, int damage, int hp, int amount);

struct enemy{
    std::string name;
    int hp;
    int damage;
    int amount;
};

int gold = 0;
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
        clearScreen();
         cout << "\n-You pick up and equip his armor, it's layered with bite marks and scratches.\n-The armor increases your max HP by 25 points\n" << endl;
        playerHP+=25;
        cout << "Current HP: " << playerHP << endl;
        cout << "\n-His sword is cracked and damage and beyond repair, but you find a dagger in his bag." << endl;
        pickedupArmor = true;
        pickedupDagger = true;
        break;
    case 2:
        clearScreen();
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
        enterCombat(pickedupArmor, pickedupDagger,playerHP, isInCombat, "Undead Knight", 60, 1, 20, fistDamage, daggerDamage, potion, hasPotion);
        
        cout << "'Glad that's over, now as I was saying'" << endl;
    }
    cout << "'Are you bit?'\n" << endl;
    cout << "1. 'No'\n2. 'Yes'" << endl;
    cin >> choice;
    if (choice == 2){
        cout << "-The guard throws his spear at you, killing you instantly." << endl;
        cout << "\nYou died!\n======GAME OVER=====" << endl;
        return 0;
    }
    clearScreen();
    cout << "-He looks weary at first, be decides to trust you" << endl;
    cout << "'Alright, I'll open the gate up, but if you're lying it'll be a quick death'" << endl;
    cout << "\n-You step through the gates, it's a small but fortified town\n-Guards roam the streets as scavengers and survivors try to sell what they can" << endl;
    cout << "\n'Look, we don't normally let people in, but the fact that I don't know you is why you may be useful'" << endl;
    finishedConvo = false;
    
    while (finishedConvo == false){
        cout << "\n1. 'What the hell is going on?'\n2. 'And if I don't want to help?'\n3. 'Okay, I'll help'\n";
        cin >> choice;
        switch (choice){
        case 1:
            clearScreen();
            cout << "'You playing dumb or do you reall not know?" << endl;
            cout << "'I guess you might not, long story short but the dead don't stay dead anymore'" << endl;
            cout << "'Make no mistake, they're not people, they don't think, they only attack and eat'" << endl;
            cout << "'Nobody is sure how or why it happened, personally I blame those Godless mathematicians'" << endl;
            break;
        case 2:
            clearScreen();
            cout << "'Then I'll kick you out and you'll figure things out on your own" << endl;
            break;
        case 3:
            clearScreen();
            cout << "'Amazing'" << endl;
            cout << "'I'll let you look around, heres 3 gold pieces, come find me when you're ready'" << endl;
            gold+3;
            finishedConvo = true;
            break;
        }
    }
    
    finishedConvo = false;
    cout << "\n-The guard walks away\n-You scan the streets and 2 different vendors are trying to flag you down\n" << endl;
    cout << "-The first one looks like a doctor\n-The other is a bearded man in a pointy hat holding a staff\n" << endl;
    while (finishedConvo == false){
        cout << "1. Approach the doctor\n2. Approach the strange man\n3. Ignore both and report back to the guard\n";
        cin >> choice;
        switch (choice){
        case 1:
            clearScreen();
            cout << "\n\nYou walk up to the doctor" << endl;
            cout << "'Hello Traveler, could I interest you in a health potion? Only 3 gold!'" << endl;
            cout << "1. Buy\n2. Leave\n";
            cin >> choice;
            switch (choice){
            case 1:
                gold-3;
                cout << "'A pleasure doing business with you!'" << endl;
                hasPotion = true;
                finishedConvo = true;
                break;
            case 2:
                clearScreen();
                cout << "\n-You walk away" << endl;
                break;
            }
            break;
            
        case 2:
            clearScreen();
            cout << "\n\nYou walk up to the strange man" << endl;
            cout << "'Hello Traveler, could I interest you in an increase in power? Only 3 gold!'" << endl;
            cout << "1. Yes\n2. Leave\n";
            cin >> choice;
            switch (choice){
            case 1:
                clearScreen();
                gold-3;
                cout << "\n'Let me see your blade...'" << endl;
                cout << "-The man begins to channel an energy between his hands and your dagger\n-Purple and blue sparks circle the air around you\n-As they fly faster, there is a grand flash of light" << endl;
                cout << "'It is done, use the power wisely'" << endl;
                cout << "-Your dagger has been imbuned with ancient power, increasing it's damage to 35" << endl;
                daggerDamage = 35;
                finishedConvo = true;
                break;
            case 2:
                clearScreen();
                cout << "\n-You walk away" << endl;
                break;
                }
        case 3:
            clearScreen();
            cout << "\n-You return to the guard" << endl;
            finishedConvo = true;
            }
        }
        
    
    cout << "\n\n-You return to the guard" << endl;
    cout << "'Good you're ready'" << endl;
    cout << "'Our scavenger teams keep running into BOSS, and we need someone to clear it out'" << endl;
    cout << "'To be honest, we're throwing everything we have at this beast, and you may be our last hope'" << endl;
    cout << "'But I'm not gonna force you to help us, say the word, and you leave now'" << endl;
    cout << "\n1. Stay and Help\n2. Leave\n";
    cin >> choice;
    switch (choice){
    case 2:
        clearScreen();
        cout << "-You decline the guards offer, leaving to town to face the BOSS on their own" << endl;
        cout << "-Their attempts fail, and the little people left starve or flee" << endl;
        cout << "-You have dammed the town, but you live on" << endl;
        cout << "\n===GAME OVER===" << endl;
    }
}

void enterCombat(bool pickedupArmor, bool pickedupDagger, int playerHP, bool isInCombat, std::string name, int HP, int amount, int damage, int fistDamage, int daggerDamage, int potion, bool hasPotion){
    isInCombat = true;
    cout << "\nEntering Combat...\n";
    cout << "Current HP: " << playerHP << endl;
    if (pickedupArmor == true){
        cout << "Armor is equipped" << endl;
    }
    if (pickedupArmor == false){
        cout << "Armor is not equipped" << endl;
    }
    if (amount == 1){
        cout << "\nYou are facing off against " << amount << " " << name << endl;
    }
    if (amount > 1){
        cout << "\nYou are facing off against " << amount << " " << name << "s" << endl;
        HP*=amount;
    }
    cout << "Enemy HP: " << HP << endl;
    while (HP > 0){
        if (playerHP <= 0){
            cout << "You died!\n======GAME OVER=====" << endl;
            exit(0);
        }
        else{
            cout << "What do you do?" << endl;
            int combatChoice;
            cout << "1. Attack\n2. Heal\n3. Skip turn\n";
            cin >> combatChoice;
            switch (combatChoice){
                case 1:
                    clearScreen();
                    if (pickedupDagger == true){
                        cout << "\n-You attack the enemy with your dagger, dealing 25 damage" << endl;
                        HP-=daggerDamage;
                        cout << "Enemy HP: " << HP << endl;
                        playerHP-=damage;
                        enemyAttack(pickedupArmor, playerHP, "Undead Knight", 20, 60, 1);
                    }
                    if (pickedupDagger == false){
                        cout << "\n-You attack the enemy with your fists, dealing 15 damage" << endl;
                        HP-=fistDamage;
                        cout << "Enemy HP: " << HP << endl;
                        playerHP-=damage;
                        enemyAttack(pickedupArmor, playerHP, "Undead Knight", 20, 60, 1);
                    }
                    
                    break;
                case 2:
                    clearScreen();
                    if (hasPotion == true){
                        cout << "You drink your health potion" << endl;
                        playerHP = playerHP+=potion;
                        hasPotion = false;
                        cout << "Current HP: " << playerHP << endl;
                        playerHP-=damage;
                        enemyAttack(pickedupArmor, playerHP, "Undead Knight", 20, 60, 1);
                    }
                    if (hasPotion == false){
                        cout << "You don't have a health potion!" << endl;
                        cout << "Current HP: " << playerHP << endl;
                        playerHP-=damage;
                        enemyAttack(pickedupArmor, playerHP, "Undead Knight", 20, 60, 1);
                    }
                    
                    break;
                case 3:
                    clearScreen();
                    cout << "Skipping turn..." << endl;
                    playerHP-=damage;
                    enemyAttack(pickedupArmor, playerHP, "Undead Knight", 20, 60, 1);
                    break;
            }
        }
    
    }
    clearScreen();
    cout << "-You won!\n" << endl;
}

void enemyAttack(bool pickedupArmor, int playerHP, std::string name, int damage, int hp, int amount){
    if (amount == 1){
        cout << "The " << name << " hits you for " << damage << " points of damage!" << endl;
        cout << "\nCurrent HP: " << playerHP << endl;
    }
    if (amount > 1){
        cout << "The " << amount << " " << name << "s hit you for " << damage << " points of damage!" << endl;
        cout << "\nCurrent HP: " << playerHP << endl;
    }

}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
