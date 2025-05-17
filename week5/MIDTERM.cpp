//------
//Using this section to show what and where the requirements are
//----
//Basic setup and structure - Yes
//Input/Output - Yes, user input throughout (choices, searching, etc)
//Output throughout the whole thing
//Variables - Yes, string, int, bool, etc
//Control flow, Yes, often followed by user choice Ex: (If user_choice = 1)
//Loops - Yes, Currently have some While loops for repeating specific commands
//and also a for loop for the entire function
//Functions - Yes, multiple for printing large amounts of info
//Strings - No, not much use for in this case
//Arrays - Yes, for the book's IDs
//Structs - Yes, main book struct
//------------------------------------------------------------------------------
//all libraries, not sure if i even used all of these though i just included any ones that have been useful before
#include<iostream>
using namespace std;
#include <cctype> 
#include <array>
using std::array;
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
void stateInfo(struct book book1, struct book book2, struct book book3);
void stateInfo1(struct book book1);
void stateInfo2(struct book book2);
void stateInfo3(struct book book3);
bool book_4 = false; 
bool book_5 = false;
struct book{ //main struct
    std::string title;
    std::string author;
    int year;
    int ID[5]; //decided to use an ID versus an ISBN, though they'll achive the same thing
    bool ischeckedout;
    int dueDate;
};

int main(){
    //-----struct def for 3 books
    book book1;
    book1.title = "To Kill a Mockingbird";
    book1.author = "Harper Lee";
    book1.year = 1960;
    book1.ID[1] = 1001;
    book1.ischeckedout = false;
    book1.dueDate = 30;
    
    book book2;
    book2.title = "The Martian";
    book2.author = "Andy Weir";
    book2.year = 2011;
    book2.ID[2] = 1002;
    book2.ischeckedout = true;
    book2.dueDate = -4;
    
    book book3;
    book3.title = "Invincible #1";
    book3.author = "Robert Kirkman";
    book3.year = 2003;
    book3.ID[3] = 1003;
    book3.ischeckedout = false;
    book3.dueDate = 30;
        
    for (int i = 1; i <= 5; i++){ //loop to repeat entire function
        //-----
        //-----start
        cout << "Library Catalog:" << "\n---------------" << endl;
        int choice; //main choice
        cout << "What would you like to do?" << "\n1. View current Books\n2. Search for a book\n3. Check out a book\n4. Return a book\n5. View out of Date Books\n6. Exit" << endl;
        cin >> choice;
        //------
        int search_choice;
        int checkOut_choice;
        if (choice == 1){
            stateInfo(book1,book2,book3);
        }
        //-------------
        if (choice == 2){ //search - asks how you'd like to search to narrow things down
            cout << "How would you like to search?" << endl;
            cout << "1. By Title\n2. By Author\n3. By Year Range\n4. By ID\n5. Exit\n";
            cin >> search_choice;
            if (search_choice == 1){
                std::string title_search;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title_search); //to read the spaces inbetween the words, i have to use the getline function
                if (title_search == book1.title){
                    stateInfo1(book1);
                }
                else if (title_search == book2.title){
                    stateInfo2(book2);
                }
                else if (title_search == book3.title){
                    stateInfo3(book3);
                }
            }
                
            if (search_choice == 2){
                std::string author_search;
                cout << "Enter Author name: ";
                cin.ignore();
                getline(cin, author_search);
                if (author_search == book1.author){
                    stateInfo1(book1);
                }
                else if (author_search == book2.author){
                    stateInfo2(book2);
                }
                else if (author_search == book3.author){
                    stateInfo3(book3);
                }
                
            }
            if (search_choice == 3){
                int year_search_1;
                int year_search_2;
                cout << "Enter Starting Year: ";
                cin >> year_search_1;
                cout << "Enter Ending Year: ";
                cin >> year_search_2; //to figure out the year range its basically if y < x < z, print x
                if (year_search_1 <= book1.year && book1.year <= year_search_2){
                    stateInfo1(book1);
                }
                if (year_search_1 <= book2.year && book1.year <= year_search_2){
                    stateInfo2(book2);
                }
                if (year_search_1 <= book3.year && book1.year <= year_search_2){
                    stateInfo3(book3);
                }
                
                }
            
            if (search_choice == 4){
                int id_search;
                cout << "Enter Book ID\n";
                cin >> id_search;
                if (id_search == book1.ID[1]){
                    stateInfo1(book1);
                }
                else if (id_search == book2.ID[2]){
                    stateInfo2(book2);
                }
                else if (id_search == book3.ID[3]){
                    stateInfo3(book3);
                }
                
                }
            }
        //---------
        if (choice ==3){
            int repeat_3 = 0;
            int check_repeat;
            while (repeat_3 < 1){
                cout << "Book 1, 2 or 3?" << endl;
                stateInfo(book1,book2,book3);
                cin >> checkOut_choice;
                if (checkOut_choice == 1){
                    if (book1.ischeckedout == false){
                        cout << "Successfully checked out!" << endl;
                        book1.ischeckedout == true;
                        
                        cout << "1. Check out another\n2. Exit";
                        cin >> check_repeat;
                            if (check_repeat == 2){
                                repeat_3++;
                            }
                    }
                    else{
                        cout << "Sorry that book is already checked out!" << endl;
                        cout << "1. Check out another\n2. Exit";
                        cin >> check_repeat;
                            if (check_repeat == 2){
                                repeat_3++;
                            }
                    }
            
                }
                if (checkOut_choice == 2){
                    if (book2.ischeckedout == false){
                        cout << "Successfully checked out!" << endl;
                        book2.ischeckedout == true;
                        
                        cout << "1. Check out another\n2. Exit";
                        cin >> check_repeat;
                            if (check_repeat == 2){
                                repeat_3++;
                            }
                    }
                    else{
                        cout << "Sorry that book is already checked out!" << endl;
                        cout << "1. Check out another\n2. Exit";
                        cin >> check_repeat;
                            if (check_repeat == 2){
                                repeat_3++;
                            }
                    }
                }
        
                if (checkOut_choice == 3){
                    if (book3.ischeckedout == false){
                        cout << "Successfully checked out!" << endl;
                        book3.ischeckedout == true;
                        
                        cout << "1. Check out another\n2. Exit";
                        cin >> check_repeat;
                            if (check_repeat == 2){
                                repeat_3++;
                            }
                    }
                    else{
                        cout << "Sorry that book is already checked out!" << endl;
                        
                        cout << "1. Check out another\n2. Exit";
                        cin >> check_repeat;
                            if (check_repeat == 2){
                                repeat_3++;
                            }
                    }
                }
            }    
    }
    
    if (choice == 4){
        int repeat_4 = 0;
        int book_4_repeat;
        while (repeat_4 != 2){ //"returning" books allowed for User Input
            if (book_4 == false){
                book book4;
            
                book4.title;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, book4.title);
            
                book4.author;
                cout << "Enter Author: ";
                cin.ignore();
                getline(cin, book4.author);
            
                book4.year;
                cout << "Enter release year: ";
                cin >> book4.year;
            
                book4.ID[4] = 1004;
                book4.ischeckedout = false;
                book4.dueDate = 30;
                book_4 = true;
                
                cout << "\nTitle: " << book4.title << endl;
                cout << "Author: " << book4.author << endl;
                cout << "Year released: " << book4.year << endl;
                cout << "ID: " << book4.ID[4] << endl;
                if (book4.ischeckedout == true){
                    cout << "Book is checked out" << endl;
                }
                if (book4.ischeckedout == false){
                    cout << "Book can be checked out" << endl;
                }
                cout << "Due date: " << book4.dueDate << " Days from today" << endl;
                
                
                cout << "1. Enter another book\n2. Exit\n";
                cin >> book_4_repeat;
                if (book_4_repeat == 1){
                    repeat_4++;
                }
                if (book_4_repeat == 2){
                    repeat_4 == 2;
                }
            }
            if (book_4_repeat == 1){
                if (book_5 == false){
                    repeat_4 = 1;
                    book book5;
                
                    book5.title;
                    cout << "Enter title: ";
                    cin.ignore();
                    getline(cin, book5.title);
                
                    book5.author;
                    cout << "Enter Author: ";
                    cin.ignore();
                    getline(cin, book5.author);
                
                    book5.year;
                    cout << "Enter release year: ";
                    cin >> book5.year;
                
                    book5.ID[5] = 1005;
                    book5.ischeckedout = false;
                    book5.dueDate = 30;
                    book_5 = true;
                    
                    cout << "\nTitle: " << book5.title << endl;
                    cout << "Author: " << book5.author << endl;
                    cout << "Year released: " << book5.year << endl;
                    cout << "ID: " << book5.ID[5] << endl;
                    if (book5.ischeckedout == true){
                        cout << "Book is checked out" << endl;
                    }
                    if (book5.ischeckedout == false){
                        cout << "Book can be checked out" << endl;
                    }
                    cout << "Due date: " << book5.dueDate << " Days from today" << endl;
                    
                    int book_5_repeat;
                    cout << "1. Enter another book\n2. Exit\n";
                    cin >> book_5_repeat;
                    if (book_5_repeat == 1){
                        repeat_4++;
                    }
                    if (book_5_repeat == 2){
                        repeat_4 == 2;
                    }
                }  
                if (repeat_4 == 2){
                    cout << "Sorry! No more books to return" << endl;
                    repeat_4 == 2;
                }
            }
        }
    }
    if (choice == 5){ //basic way of telling what is overdue by counting based off the due date
        int overdue_count;
        if (book1.dueDate < 0){
            overdue_count++;
        }
        if (book2.dueDate < 0){
            overdue_count++;
        }
        if (book3.dueDate < 0){
            overdue_count++;
        }
        cout << overdue_count << " overdue books found: " << endl;
        if (book1.dueDate < 0){
            stateInfo1(book1);
        }
        if (book2.dueDate < 0){
            stateInfo1(book2);
        }
        if (book3.dueDate < 0){
            stateInfo1(book3);
        }
    }
    if (choice == 6){
        cout << "Exiting..." << endl;
        return 0;
    }
}
}

//------------------------------------------------------------------------------
void stateInfo(struct book book1, struct book book2, struct book book3){ //function to print all 3 books
        cout << "\nTitle: " << book1.title << endl;
        cout << "Author: " << book1.author << endl;
        cout << "Year released: " << book1.year << endl;
        cout << "ID: " << book1.ID[1] << endl;
        if (book1.ischeckedout == true){
            cout << "Book is checked out" << endl;
        }
        if (book1.ischeckedout == false){
            cout << "Book can be checked out" << endl;
        }
        cout << "Due date: " << book1.dueDate << " Days from today" << endl;
        
        cout << "\nTitle: " << book2.title << endl;
        cout << "Author: " << book2.author << endl;
        cout << "Year released: " << book2.year << endl;
        cout << "ID: " << book2.ID[2] << endl;
        if (book2.ischeckedout == true){
            cout << "Book is checked out" << endl;
        }
        if (book2.ischeckedout == false){
            cout << "Book can be checked out" << endl;
        }
        cout << "Due date: " << book2.dueDate << " Days from today" << endl;
        
        cout << "\nTitle: " << book3.title << endl;
        cout << "Author: " << book3.author << endl;
        cout << "Year released: " << book3.year << endl;
        cout << "ID: " << book3.ID[3] << endl;
        if (book3.ischeckedout == true){
            cout << "Book is checked out" << endl;
        }
        if (book3.ischeckedout == false){
            cout << "Book can be checked out" << endl;
        }
        cout << "Due date: " << book3.dueDate << " Days from today" << endl;
}

void stateInfo1(struct book book1){ //function to print book 1
     cout << "\nTitle: " << book1.title << endl;
        cout << "Author: " << book1.author << endl;
        cout << "Year released: " << book1.year << endl;
        cout << "ID: " << book1.ID[1] << endl;
        if (book1.ischeckedout == true){
            cout << "Book is checked out" << endl;
        }
        if (book1.ischeckedout == false){
            cout << "Book can be checked out" << endl;
        }
        cout << "Due date: " << book1.dueDate << " Days from today" << endl;
}
void stateInfo2(struct book book2){//function to print book 2
     cout << "\nTitle: " << book2.title << endl;
        cout << "Author: " << book2.author << endl;
        cout << "Year released: " << book2.year << endl;
        cout << "ID: " << book2.ID[2] << endl;
        if (book2.ischeckedout == true){
            cout << "Book is checked out" << endl;
        }
        if (book2.ischeckedout == false){
            cout << "Book can be checked out" << endl;
        }
        cout << "Due date: " << book2.dueDate << " Days from today" << endl;
}
void stateInfo3(struct book book3){//function to print book 3
     cout << "\nTitle: " << book3.title << endl;
        cout << "Author: " << book3.author << endl;
        cout << "Year released: " << book3.year << endl;
        cout << "ID: " << book3.ID[3] << endl;
        if (book3.ischeckedout == true){
            cout << "Book is checked out" << endl;
        }
        if (book3.ischeckedout == false){
            cout << "Book can be checked out" << endl;
        }
        cout << "Due date: " << book3.dueDate << " Days from today" << endl;
}
