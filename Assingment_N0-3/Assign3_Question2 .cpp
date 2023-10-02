/*
Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
collected. Model this tollbooth with a class called tollbooth.
The two data items are a type unsigned int to hold the total number of cars, and a type double to
hold the total amount of money collected.
A constructor initializes all data members to 0. A member function called payingCar() increments
the car total and adds 0.50 to the cash total. An other function, called nopayCar()
increments the car total but adds nothing to the cash total. Finally, a member function called
printOnConsole() displays the two totals and number of paying as well as non paying cars total.
( write a menu driven code for it)
*/

#include <iostream>
#include <string.h>
using namespace std;

class Tollbooth
{
private:
    int paynocars;
    int nonpaynocars;
    double amount;

public:

    Tollbooth()
    {
        this->paynocars=0;
        this->nonpaynocars=0;
        this->amount=0;
    }

    int payingCar()
    {
        paynocars = paynocars + 1;
        amount = amount + 0.5;
    }
    int nonpayingCar()
    {
        nonpaynocars = nonpaynocars + 1;
    }
    void printOnConsole()
    {
        cout << "The total number of paying cars is= " << paynocars << endl;
        cout << "The total number of NON--paying cars is= " << nonpaynocars << endl;
        cout << "The total Amount of money collected is= " << amount << endl;
    }

    int carTotal()
    {
        int total;
        total = this->paynocars + this->nonpaynocars;
        return total;
    }

    double getAmount()
    {
        return this->amount;
    }

    int getPayCar()
    {
        return this->paynocars;
    }

    int getNonPayCar()
    {
        return this->nonpaynocars;
    }
};

enum emenu
{
    Exit,
    pay,
    nopay
};

emenu menu()
{
    int choice;
    cout << endl;
    cout << "1-car has paid" << endl;
    cout << "2-car has not paid " << endl;
    cout << "0- exit" << endl;
    cin >> choice;
    return emenu(choice);
}

int main()
{
    Tollbooth t1;

    emenu ch;
    
    while ((ch = menu()) != Exit)
    {
        switch (ch)
        {
        case pay:
            // car paid increment in cash_total
            t1.payingCar();
           

            cout << "total cash collected = " <<t1.getAmount()<< endl;
            cout<<"Total no paying cars = "<<t1.getPayCar()<<endl;
            cout<<"Total no Non paying cars = "<<t1.getNonPayCar()<<endl;
            cout << "total cars passed " <<t1.carTotal();
            break;

        case nopay:
             // car paid increment in cash_total
            t1.nonpayingCar();

            cout << "total cash collected = " <<t1.getAmount()<< endl;
            cout<<"Total no paying cars = "<<t1.getPayCar()<<endl;
            cout<<"Total no Non paying cars = "<<t1.getNonPayCar()<<endl;
            cout << "total cars passed " <<t1.carTotal();
            break;

        default:
            cout << "Pls Enter Vaild Option" << endl;
        }
    }
    return 0;
}
