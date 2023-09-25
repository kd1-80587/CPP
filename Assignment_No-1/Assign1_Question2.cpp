/*Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();*/

#include <iostream>
using namespace std;

struct Date
{
private:
    int day;
    int month;
    int year;

public:
    void initDate()
    {
        this->day = 01;
        this->month = 01;
        this->year = 1900;
    }

    void printDateOnConsole()
    {
        cout << "DATE = " << this->day << " / " << this->month << " / " << this->year << endl;
    }

    void acceptDateFromConsole()
    {
        cout << "\n Enter Day= ";
        cin >> this->day;
        cout << "\n Enter Month= ";
        cin >> this->month;
        cout << "\n Enter Year= ";
        cin >> this->year;
    }

    bool isLeapYear()
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            // cout << "Its Leap Year" << endl;
            return true;
        }
        else
        {
            // cout << "Its not Leap Year" << endl;
            return false;
        }
    }
};

int main()
{
    int opt;
    struct Date d;

    do
    {
        cout << "**************************************************************************************" << endl;
        cout << "1. Initial Date \n 2.Enter Date \n 3.Print Date  \n 4.Check for Leap Year \n 0.Exit\n"
             << endl;
        cout << "**************************************************************************************" << endl;

        cout << "Enter Option : ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            d.initDate();

            break;

        case 2:

            d.acceptDateFromConsole();

            break;

        case 3:

            d.printDateOnConsole();

            break;

        case 4:

            d.acceptDateFromConsole();
            int x;
            x = d.isLeapYear();
            if (x == true)
            {
                cout << "Its Leap Year" << endl;
            }
            else
            {
                cout << "Its not Leap Year" << endl;
            }

            break;

        case 0:

            break;

        default:

            cout << "Invalid Input" << endl;

            break;
        }
    } while (opt != 0);

    return 0;
}