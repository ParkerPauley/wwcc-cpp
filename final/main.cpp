/*
   Interactive Story Game: The Undead Village
   Author: Parker Pauley
   Date: 6/17/2025
   
   ===Project Features===
    * Variables (3+ types): In variables.h
    * If/else statements: 94, 106, etc
    * Switch statement:  67, 123, etc
    * While Loop: 120, 312, etc
    * Function w/ return: 384
    * Void function: 287
    * Function w/ params: 384
    * Array usage:  56
    * Struct/Class: 44
    * Enum: 33
    * File Reading: 32
    * File Writing: 371
    * Modern Feature (): auto (in variables.h), ranged based for loop (line 287)
   */
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
#include <fstream>
#include "variables.h"
enum ending {
    GOOD,
    BAD
    
};


void enterCombat(bool pickedupArmor, bool pickedupDagger, int playerHP, bool isInCombat, std::string name, int HP, int amount, int damage, int fistDamage, int daggerDamage, int potion, bool hasPotion);
void clearScreen();
int enemyAttack(bool pickedupArmor, int playerHP, std::string name, int damage, int hp, int amount);

struct enemy{
    std::string name;
    int hp;
    int damage;
    int amount;
};


std::string playerName;

int main(){
    clearScreen();
    int level[4];
    level[0] = 0;
    level[1] = 100;
    level[2] = 200;
    level [3] = 300;
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
    
    cout << "=======Enter Name:=======\n";
    cin >> playerName;
    clearScreen();
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
    cout << "\n-For succesfully entering the town, you gain " << level[1] << "xp and level up" << endl;
    totalLevel++;
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
            if (pickedupDagger == false){
                cout << "'Here's a spare dagger, I know it's not much but it's all I could find'" << endl;
                pickedupDagger = true;
            }
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
            break;
        case 3:
            clearScreen();
            cout << "\n-You return to the guard" << endl;
            finishedConvo = true;
            break;
            }
        }
        
    
    cout << "\n\n-You return to the guard" << endl;
    cout << "'Good you're ready'" << endl;
    cout << "'Our scavenger teams keep running into the necromancer, and we need someone to clear it out'" << endl;
    cout << "'To be honest, we're throwing everything we have at this beast, and you may be our last hope'" << endl;
    cout << "'But I'm not gonna force you to help us, say the word, and you leave now'" << endl;
    cout << "\n1. Stay and Help\n2. Leave\n";
    cin >> choice;
    switch (choice){
    case 2:
        clearScreen();
        ending leave = BAD;
        cout << "-You decline the guards offer, leaving to town to face the necromancer on their own" << endl;
        cout << "-Their attempts fail, and the little people left starve or flee" << endl;
        cout << "-You have dammed the town, but you live on" << endl;
        cout << "\n===GAME OVER===" << endl;
        break;
    }
    clearScreen();
    cout << "'Great! The necromancer is held up in the old church just north of town'" << endl;
    if (pickedupArmor == true){
        cout << "'Lets get you patched up a bit and you'll be on your way'" << endl;
        while (playerHP < 125){
            playerHP++;
        }
            cout << "Current HP: " << playerHP << endl;
        }
    else{
            cout << "'Lets get you set up and you'll be on your way'" << endl;
    }
    cout << "\n-After a good nights rest, you're sent out to face the necromancer" << endl;
    cout << "\n-For your preperation, you gain " << level[2] << " xp and level up" << endl;
    totalLevel++;
    cout << "\n-The sky outside the town is dark, and a deep fog rests around the church" << endl;
    
    cout << "\n-As you approach, you see 2 skeleton guards standing near the entrance" << endl;
    cout << "-Fighting them may prove risky, but they could possibly have loot" << endl;
    cout << "\n1. Fight them\n2. Sneak Around\n";
    cin >> choice;
    switch (choice){
    case 1:
        clearScreen();
        enterCombat(pickedupArmor, pickedupDagger,playerHP, isInCombat, "Skeletal Guards", 40, 2, 20, fistDamage, daggerDamage, potion, hasPotion);
        cout << "\n-You open their bags and find two health potions" << endl;
        cout << "-You use one to restore your HP, and keep the other" << endl;
        hasPotion = true;
        while (playerHP < 125){
            playerHP++;
        }
        break;
    case 2:
        clearScreen();
        cout << "-You successfully sneak past them" << endl;
        break;
    }
    cout << "\n-You walk into the halls of the dying church, the walls are falling apart" << endl;
    cout << "\n-The necromancer is sitting in a throne of skulls and bones" << endl;
    cout << "\n'Foolish Mortal, you dare to challenge me?" << endl;
    cout << "1. Fight\n2. Offer to serve him\n";
    cin >> choice;
    switch (choice){
    case 1:
        
        enterCombat(pickedupArmor, pickedupDagger,playerHP, isInCombat, "Necromancer", 100, 1, 30, fistDamage, daggerDamage, potion, hasPotion);
        cout << "\n-You defeated the Necromancer!" << endl;
        cout << "\n-For your success, you gain " << level[3] << " xp and level up" << endl;
        totalLevel++;
        cout << "\n-You've saved the town from this evil, but there are more Necromancers out there..." << endl;
        
        break;
    case 2:
        cout << "\n-You join the necromancer's forces" << endl;
        cout << "\n-For your success, you gain " << level[3] << " xp and level up" << endl;
        totalLevel++;
        cout << "\n-Learning his power, you follow their way of evil, spreading death and pain throughout the region" << endl;
        break;
    }
    cout << "\n\n===THE END===" << endl;
    cout << "\nThank you for playing!" << endl;
    int total = 0;
    for (int level : level) {
        total++;
    }
    cout << "Total score: " << total << endl;
}
void enterCombat(bool pickedupArmor, bool pickedupDagger, int playerHP, bool isInCombat, std::string name, int HP, int amount, int damage, int fistDamage, int daggerDamage, int potion, bool hasPotion){
    totalEncounters++;
    isInCombat = true;
    cout << "\nEntering Combat...\n";
    cout << " O |\n/|L|\n/ |" << endl;
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
                        cout << "\n-You attack the enemy with your dagger, dealing " << daggerDamage << " damage" << endl;
                        HP-=daggerDamage;
                        cout << "Enemy HP: " << HP << endl;
                        playerHP-=damage;
                        enemyAttack(pickedupArmor, playerHP, name, damage, HP, amount);
                    }
                    if (pickedupDagger == false){
                        cout << "\n-You attack the enemy with your fists, dealing 15 damage" << endl;
                        HP-=fistDamage;
                        cout << "Enemy HP: " << HP << endl;
                        playerHP-=damage;
                        enemyAttack(pickedupArmor, playerHP, name, damage, HP, amount);
                    }
                    
                    break;
                case 2:
                    clearScreen();
                    if (hasPotion == true){
                        cout << "You drink your health potion" << endl;
                        playerHP = playerHP+=potion;
                        hasPotion = false;
                        cout << "Current HP: " << playerHP << endl;
                        
                    }
                    if (hasPotion == false){
                        cout << "You don't have a health potion!" << endl;
                        cout << "Current HP: " << playerHP << endl;
                        playerHP-=damage;
                        enemyAttack(pickedupArmor, playerHP, name, damage, HP, amount);
                    }
                    
                    break;
                case 3:
                    clearScreen();
                    cout << "Skipping turn..." << endl;
                    playerHP-=damage;
                    enemyAttack(pickedupArmor, playerHP, name, damage, HP, amount);
                    break;
            }
        }
    
    }
    clearScreen();
    cout << "-You won!\n" << endl;
    
    std::ofstream outFile("game_summary.txt");

    
    if (outFile.is_open()) {
        outFile << "=== Game Summary ===\n";
        outFile << "Total Combat Encounters: " << totalEncounters << "\n";
        outFile << "Final Level: " << totalLevel << "\n";
        outFile.close();
    } else {
        std::cerr << "Error: Could not open file for writing.\n";
    }
}

int enemyAttack(bool pickedupArmor, int playerHP, std::string name, int damage, int hp, int amount){
    playerHP-=damage;
    cout << "The " << name << " hits you for " << damage << " points of damage!" << endl;
    cout << "\nCurrent HP: " << playerHP << endl;
    return 0;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
