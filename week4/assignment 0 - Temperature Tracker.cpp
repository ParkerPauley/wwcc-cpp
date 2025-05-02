#include<iostream>
using namespace std;
#include <cctype> 
#include <array>
#include <algorithm>
#include <vector>
int averagetemp(int day1,int day2,int day3,int day4,int day5,int day6,int day7);
int main(){
    
    int day1,day2,day3,day4,day5,day6,day7;
    
    cout << "Temperature Tracker\n-------------------" << endl;
    
    cout << "Enter Temperature for Day 1: ";
    cin >> day1;
    cout << "Enter Temperature for Day 2: ";
    cin >> day2;
    cout << "Enter Temperature for Day 3: ";
    cin >> day3;
    cout << "Enter Temperature for Day 4: ";
    cin >> day4;
    cout << "Enter Temperature for Day 5: ";
    cin >> day5;
    cout << "Enter Temperature for Day 6: ";
    cin >> day6;
    cout << "Enter Temperature for Day 7: ";
    cin >> day7;
    
    int arr[] = { day1, day2, day3, day4, day5, day6, day7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nTemperature Analysis:\n";
    averagetemp(day1,day2,day3,day4,day5,day6,day7);
    int avtemp = (((day1)+(day2)+(day3)+(day4)+(day5)+(day6)+(day7))/7);
    
    int min_num = *min_element(arr, arr + n);
    cout << "The Lowest temp was: " << min_num
         << endl;
        
    int max_num = *max_element(arr, arr + n);
    cout << "The Highest temp was: " << max_num
         << endl;
    
    cout << "Above average temps: " << endl;
    if (day1 > avtemp){
        cout << day1 << endl;
    }
    if (day2 > avtemp){
        cout << day2 << endl;
    }
    if (day3 > avtemp){
        cout << day3 << endl;
    }
    if (day4 > avtemp){
        cout << day4 << endl;
    }
    if (day5 > avtemp){
        cout << day5 << endl;
    }
    if (day6 > avtemp){
        cout << day6 << endl;
    }
    if (day7 > avtemp){
        cout << day7 << endl;
    }
    
}

int averagetemp(int day1,int day2,int day3,int day4,int day5,int day6,int day7){
    
    cout << "The average temperature is: " << (((day1)+(day2)+(day3)+(day4)+(day5)+(day6)+(day7))/7) << " Degrees" << endl;
    return 0;
}
