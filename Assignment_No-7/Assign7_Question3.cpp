#include <iostream>
using namespace std;

class employee // base class
{
private:
    int id;
    float sal;
    string designation;

public:
    employee()
    {
        cout << "Employee Class Constructor" << endl;
        this->id = 0;
        this->sal = 0;
        this->designation = "";
    }
    employee(int id, float sal)
    {
        this->id = id;
        this->sal = sal;
        this->designation = designation;
    }
    int get_id()
    {
        return this->id;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    float get_sal()
    {
        return this->sal;
    }
    void set_sal(float sal)
    {
        this->sal = sal;
    }
    string get_designation()
    {
        return this->designation;
    }
    void set_designation(string designation)
    {
        this->designation = designation;
    }

    virtual void accept()
    {
        cout << "Enter the ID = ";
        cin >> this->id;
        cout << "Enter the Salary = ";
        cin >> this->sal;
        cout << "Enter the Designation = ";
        cin >> this->designation;
    }
   virtual void display()
    {
        cout << "ID = " << this->id << endl;
        cout << "Salary = " << this->sal << endl;
        cout << "Designation = " << this->designation << endl;
    }
    virtual ~employee()
    {

    }
};
class manager : virtual public employee // derived class1
{
private:
    float bonus;

public:
    manager()
    {
        cout << "Manager Class Constructor" << endl;
        this->bonus = 0;
    }
    manager(float bonus, int id, float sal, string designation)
    {
        employee::set_id(id);
        employee::set_sal(sal);
        set_designation(designation);
        this->bonus = bonus;
    }
    float get_bonus()
    {
        return this->bonus;
    }
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }
    void accept()
    {
        employee::accept();
        cout << "Enter the Bonus = ";
        cin >> this->bonus;
    }
    void display()
    {
        employee::display();
        cout << "Bonus = " << this->bonus << endl;
    }

protected:
    void accept_manager()
    {
        cout << "Bonus = ";
        cin >> this->bonus;
    }
    void display_manager()
    {
        cout << "Bonus is = " << bonus << endl;
    }
};
class salesman : virtual public employee // derived class2
{
private:
    float comm;

public:
    salesman()
    {
        cout << "Salesman Class Constructor" << endl;
        this->comm = 0;
    }
    salesman(float comm, float bonus, int id, float sal, string designation)
    {
        employee::set_id(id);
        employee::set_sal(sal);
        employee::set_designation(designation);
        this->comm = comm;
    }
    float get_comm()
    {
        return this->comm;
    }
    void set_comm(float comm)
    {
        this->comm = comm;
    }
    void accept()
    {
        employee::accept();
        cout << "Enter the Commison = ";
        cin >> this->comm;
    }
    void display()
    {
        employee::display();
        cout << "Comm = " << this->comm << endl;
    }

protected:
    void accept_salesman()
    {
        cout << "Commison = ";
        cin >> this->comm;
    }
    void display_salesman()
    {
        cout << "Commision is = " << comm << endl;
    }
};
class sales_manager : public salesman, public manager // indirect derived class
{
public:
    sales_manager()
    {
        cout << "Sales Manager Class Constructor" << endl;
    }
    sales_manager(int id, float sal, float bonus, float comm, string designation)
    {
        employee::set_id(id);
        employee::set_sal(sal);
        employee::set_designation(designation);
        manager::set_bonus(bonus);
        salesman::set_comm(comm);
    }
    void accept()
    {
        employee::accept();
        manager::accept_manager();
        salesman::accept_salesman();
    }
    void display()
    {
        employee::display();
        manager::display_manager();
        salesman::display_salesman();
    }
};
int menu()
{
    int choice;
    cout << "--------------------" << endl;
    cout << "0. Exit" << endl;
    cout << "1. EMPLOYEE" << endl;
    cout << "2. Display the count of employess with designation" << endl;
    cout << "3. Display respective designation employees" << endl;
    cout << "Enter Your Chocie = ";
    cin >> choice;
    cout << "--------------------" << endl;
    return choice;
}
int submenu()
{
    int choise;
    cout << "1.Accept  EMPLOYEE for MANAGER" << endl;
    cout << "2.Accept  EMPLOYEE for SALESMAN" << endl;
    cout << "3.Accept  EMPLOYEE for SALES MANAGER" << endl;
    cout << "Enter Your Chocie = ";
    cin >> choise;
    cout << "--------------------" << endl;
    return choise;
}
// int submenu1()
// {
//     int choiise;
//     cout << "1.Display  EMPLOYEE for MANAGER" << endl;
//     cout << "2.Display  EMPLOYEE for SALESMAN" << endl;
//     cout << "3.Display  EMPLOYEE for SALES MANAGER" << endl;
//     cout << "Enter Your Chocie = ";
//     cin >> choiise;
//     cout << "--------------------" << endl;
//     return choiise;
// }
int main()
{
    int choice;
    employee *arr[10];
    int index = 0;
    int m = 0, s = 0, sm = 0;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            switch (submenu())
            {
            case 1:
                if (index < 10)
                {
                    arr[index] = new manager();
                    arr[index]->accept();
                    index++;
                    m++;
                }
                else
                    cout << "Array is Full, Cannot add the employee Object.." << endl;
                break;
            case 2:
                if (index < 10)
                {
                    arr[index] = new salesman();
                    arr[index]->accept();
                    index++;
                    s++;
                }
                else
                    cout << "Array is Full, Cannot add the manager Object.." << endl;
                break;
            case 3:
                if (index < 10)
                {
                    arr[index] = new sales_manager();
                    arr[index]->accept();
                    index++;
                    sm++;
                }
                else
                    cout << "Array is Full, Cannot add the sales_manager Object.." << endl;
                break;

            default:
                cout << "Wrong Choice ..." << endl;
                break;
            }
        case 2:
            cout << " Manager count = " << m << endl;
            cout << " Salesman count = " << s << endl;
            cout << " SalesManager count = " << sm << endl;
            break;
        case 3:
            for (int i = 0; i < index; i++)
                arr[i]->display();
            break;

        default:
            cout << "Wrong Choice ..." << endl;
            break;
        }
    }
    for (int i = 0; i < index; i++)
        delete arr[i];

    cout << "Thank you for using our app..." << endl;

    return 0;
}