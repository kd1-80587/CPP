#include "./menu.h"
#include<iostream>
using namespace std;
Emenu menu()
{
     int choice;
    cout << "*******************" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. To accept " << endl;
    cout << "2. Display volume" << endl;
    cout << "3. to view parameters" << endl;
    cout << "Enter your choice = ";
    cin >> choice;
    cout << "*******************" << endl;
    return Emenu(choice);
}