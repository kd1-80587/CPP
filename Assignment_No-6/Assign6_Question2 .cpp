/*Q2. Implement following classes. Test all functionalities in main() of each created class. Note that
employee is inherited into manager and salesman. Insted of char[] use string datatype.*/

#include <iostream>
using namespace std;

class employee
{
private:
    int id;
    float sal;

public:
    employee()
    {
        cout << "inside employee constor" << endl;
    }

    employee(int id, float sal)
    {
        this->id = 0;
        this->sal = 0;
    }

    int get_id()
    {
        return this->id;
    }
    float get_sal()
    {
        return this->sal;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_sal(float sal)
    {
        this->sal = sal;
    }

    void display()
    {
        cout << "reqired Employee Id is:" << id << endl;
        cout << "reqired Employee salary is:" << sal << endl;
    }

    void accept()
    {
        cout << "Enter Employee Id:" << endl;
        cin >> id;
        cout << "Enter Employee Salary:" << endl;
        cin >> sal;
    }
};

class manager : virtual public employee
{
private:
    float bonus;

public:
    manager()
    {
        cout << "inside manager constor" << endl;
    }

    manager(int id, float sal, float bonus) //: employee(id, sal)
    {
        employee::set_id(id);
        employee::get_id();
        employee::set_sal(sal);
        employee::get_sal();
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

protected:
    void display_manager()
    {
        //employee::display();
        cout << "required Employee Id is:" << bonus << endl;
    }

    void accept_manager()
    {
        //employee::accept();
        cout << "Enter manager bonous:" << endl;
        cin >> bonus;
    }
};

class salesman : virtual public employee
{
private:
    float comm;

public:
    salesman()
    {
        cout << "inside salesman constor" << endl;
    }

    salesman(int id, float sal, float comm) //: employee(id, sal)
    {
        employee::set_id(id);
        //employee::get_id();
        employee::set_sal(sal);
        //employee::get_sal();
        this->comm = comm;
    }
    void set_comm(float comm)
    {
        this->comm = comm;
    }

    float get_comm()
    {
        return this->comm;
    }

protected:
    void display_salesman()
    {
        // employee::display();
        cout << "required salesman comm:" << comm << endl;
    }

    void accept_salesman()
    {
        // employee::accept();
        cout << "Enter salesman comm:" << endl;
        cin >> comm;
    }
};

class sales_manager : public manager, public salesman
{

public:
    sales_manager()
    {
        cout << "inside sales_manager constor" << endl;
    }
    sales_manager(int id, float sal, float bonus, float comm) //: employee(id, sal), manager(bonus), salesman(comm)
    {
        employee::set_id(id);
        employee::set_sal(sal);
        // employee::get_sal();
        manager::set_bonus(bonus);
        // manager::get_bonus();
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

int main()
{
    sales_manager s1;
    cout<<"***************************************************"<<endl;
    s1.accept();
    cout<<"***************************************************"<<endl;
    s1.display();
    cout<<"***************************************************"<<endl;

    return 0;
}
