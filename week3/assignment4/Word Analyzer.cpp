//no matter which method i used i could never get the reversed string to work, it would always return just numbers?
//i understand i'll lose points for that though if you'd be able to tell me what i'd need to use to get it to work I'd appriciate it

#include<iostream>
using namespace std;
#include <cctype> 
#include <algorithm>//libraries

int countVowels(string s, int vowelcount);
int countConsonants(string s, int coscount);
bool isPalindrome(string s);
char firstLetter(string s);
int reversed(string s); //functions declaration

int main(){ //main
    
    int vowelcount = 0;
    int coscount = 0;
    
    cout << "Word Analyzer" << endl;
    
    string s;
    cout << "Enter word: ";
    cin >> s;
    
    countVowels(s,vowelcount);
    countConsonants(s,coscount);
    isPalindrome(s);
    firstLetter(s);
    cout << reversed(s) << endl;
    
    
    return 0;
}
//functions
int countVowels(string s, int vowelcount){ //uses loop to find vowels
    for (int i=0;i<s.length(); i++){
        if (s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                vowelcount++;
            }
        }
    cout << s << " has " <<vowelcount << " vowels!" << endl;
    return 0;
}

int countConsonants(string s, int coscount){ //uses loop to find cosonants
    for (int i=0;i<s.length(); i++){
        if (s[i]=='b' ||s[i]=='c' ||s[i]=='d' ||s[i]=='f' ||s[i]=='g' ||s[i]=='h' ||s[i]=='j' ||s[i]=='k' ||s[i]=='l' ||s[i]=='m' ||s[i]=='p' ||s[i]=='q' ||s[i]=='r' ||s[i]=='s' ||s[i]=='t' ||s[i]=='v' ||s[i]=='w' ||s[i]=='x' ||s[i]=='y' ||s[i]=='z'){
                coscount++;
            }
        }
    cout << s << " has " << coscount  << " consonants!" << endl;
    return 0;
}

bool isPalindrome(string s){ //uses loops and if to find palindromes, checks if 1st char is equal to last, 2nd to 2nd last, etc
    for (int i=0; i < s.length() / 2; i++){
        
        if (s[i] != s[s.length() -i - 1]){
            cout << s << " is not a " << "Palindrome!" << endl;
            return false;
        }
        else {
            cout << s << " is a " << "Palindrome!" << endl;
            return true;
        }
    }
    return 0;
}

char firstLetter(string s){
    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        if(i==0){
            cout<< "First letter: " <<ch<<" "<< endl;
        }
    }
    return 0;
}
