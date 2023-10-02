#include <iostream>
using namespace std;

class date
{
private:
    int day;
    int month;
    int year;

public:
    date()
    {
        this->day = 01;
        this->month = 01;
        this->year = 1900;
    }

    date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int get_day()
    {
        return this->day;
    }

    int get_month()
    {
        return this->month;
    }

    int get_year()
    {
        return this->year;
    }

    void set_day(int day)
    {
        this->day = day;
    }

    void set_month(int month)
    {
        this->month = month;
    }

    void set_year(int year)
    {
        this->year = year;
    }

    void acceptdate()
    {
        cout << "Enter Day = ";
        cin >> day;
        cout << "Enter month= ";
        cin >> month;
        cout << "Enter year = ";
        cin >> year;
    }

    void displaydate()
    {
        cout << "Date= " << day << "/" << month << "/" << year << endl;
    }

    bool is_leap_year()
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            return true;
        else
            return false;
    }
};

class person
{
private:
    string name;
    string address;
    date birth_date;

public:
    person()
    {
        this->name = "xyz";
        this->address = "xyz";
    }

    person(string name, string address, int day, int month, int year) //: birth_date(day, month, year)
    {
        this->name = name;
        this->address = address;
        birth_date.set_day(day);
        birth_date.set_month(month);
        birth_date.set_year(year);
    }

    string get_name()
    {
        return this->name;
    }

    string get_address()
    {
        return this->address;
    }

    void set_name(string)
    {
        this->name = name;
    }

    void set_address(string)
    {
        this->address = address;
    }

    date get_birth_date()
    {
        return this->birth_date;
    }

    void set_birth_date(date birth_date)
    {
        this->birth_date = birth_date;
    }

    void accept()
    {
        cout << "Enter Name = ";
        // cin >> this->name;
        getline(cin, name);
        cout << "Enter Address = ";
        // cin >> this->address;
        getline(cin, address);
        cout << "Enter Date of Birth => ";
        this->birth_date.acceptdate();
        cout << "##############################################################################" << endl;
    }

    void display()
    {
        cout << "Name=> " << this->name << endl;
        cout << "Address=> " << this->address << endl;
        cout << "Birth ";
        this->birth_date.displaydate();
        cout << "**************************************************************************" << endl;
    }
};

class employee
{
private:
    int id;
    float sal;
    string dept;
    date joining;

public:
    employee()
    {
        this->id = 0;
        this->sal = 0;
        this->dept = "abc";
    }

    employee(int id, float sal, string dept, int day, int month, int year) //: joining(day, month, year)
    {
        this->id = id;
        this->sal = sal;
        this->dept = dept;
        // this->joining.set_day(day);
        // this->joining.set_month(month);
        // this->joining.set_year(year);
    }

    int get_id()
    {
        return this->id;
    }

    float get_sal()
    {
        return this->sal;
    }

    string get_dept()
    {
        return this->dept;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    void set_sal(float sal)
    {
        this->sal = sal;
    }

    void set_dept(string dept)
    {
        this->dept = dept;
    }

    date get_joining_date()
    {
        return this->joining;
    }

    void set_joining_date(date joining)
    {
        this->joining = joining;
    }

    void accept()
    {
        cout << "Enter Employee ID = ";
        cin >> this->id;
        cout << "Enter Salary = ";
        cin >> this->sal;
        getchar();
        cout << "Enter Department = ";
        // cin >> this->dept;
        getline(cin, dept);
        cout << "Enter Date of Joining => ";
        this->joining.acceptdate();
        cout << "##############################################################################" << endl;
    }

    void display()
    {
        cout << "Employee Id = " << this->id << endl;
        cout << "Employee Salary = " << this->sal << endl;
        cout << "Employee Department = " << this->dept << endl;
        cout << "Employee Date of Joining => ";
        this->joining.displaydate();
        cout << "**************************************************************************" << endl;
    }
};

int main()
{
    // person p;
    // p.accept();
    // p.display();
    person p1("Vinod Patil", "Vishrambagh Sangli", 8, 5, 1997);
    p1.display();

    employee e;
    e.accept();
    e.display();
    //employee e1(123, 10000, "Mechanical", 1, 1, 2023);
    //e1.display();

    return 0;
}
