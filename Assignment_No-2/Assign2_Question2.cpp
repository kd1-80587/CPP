/*Q2. Write a class Address. Implement constructors, getters, setters, accept(), and display() methods.
Instead of char[] use string datatype*/

#include <iostream>
using namespace std;

namespace Naddress
{
    class Address
    {
    private:
        string building;
        string street;
        string city;
        int pin;

    public:
        Address()
        {
            this->building = "xyz";
            this->street = "xyz";
            this->city = "xyz";
            this->pin = 0;
        }

        Address(string building, string street, string city, int pin)
        {
            this->building = building;
            this->street = street;
            this->city = city;
            this->pin = pin;
        }

        void accept()
        {
            getchar();
            cout << "Enter Building =";
            // cin >> this->building;
            getline(cin, building);
            cout << "Enter street =";
            // cin >> this->street;
            getline(cin, street);

            cout << "Enter city =";
            // cin >> this->city;
            getline(cin, city);

            cout << "Enter pin =";
            cin >> this->pin;
        }

        void display()
        {
            cout << "Address = " << this->building << " ," << this->street << " ," << this->city << " - " << this->pin << endl;
        }

        string get_building()
        {
            return this->building;
        }

        string get_street()
        {
            return this->street;
        }

        string get_city()
        {
            return this->city;
        }

        int get_pin()
        {
            return this->pin;
        }

        void set_building(string building)
        {
            this->building = building;
        }

        void set_street(string street)
        {
            this->street = street;
        }

        void set_city(string city)
        {
            this->city = city;
        }

        void set_pin(int pin)
        {
            this->pin = pin;
        }
    };
}

using namespace Naddress;

int menu()
{
    int choice;

    cout << "*****************************************************" << endl;
    cout << " 0.Exit     1.Enter Address      2.Show Address " << endl;
    cout << "Enter Choice = ";
    cin >> choice;
    cout << "*****************************************************" << endl;

    return choice;
}

int main()
{
    Address address;
    int choice;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            address.accept();
            break;

        case 2:
            address.display();
            break;

        default:
            cout << "Plz Enter valid Input" << endl;
            break;
        }
    }

    return 0;
};