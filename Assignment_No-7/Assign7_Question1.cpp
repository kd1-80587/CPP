#include<iostream>
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
        this->day = 0;
        this->month = 0;
        this->year = 0;
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
    void set_day(int day)
    {
        this->day=day;
    }
    int get_month()
    {
        return this->month;
    }
    void set_month(int month)
    {
        this->month=month;
    }
    int get_year()
    {
        return this->year;
    }
    void set_year(int year)
    {
        this->year=year;
    }
    void acceptDate()
    {
        cout << "Enter the day = ";
        cin >> this->day;
        cout << "Enter the month = ";
        cin >> this->month;
        cout << "Enter the year = ";
        cin >> this->year;
    }
    void displayDate()
    {
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
    bool is_leap_year()
    {
        if (((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0)))
            return true;
        else
            return false;
    }
};

class person
{
private:
    string name;
    string addr;
    date birth_date;
public:
    person()
    {
        this->name="";
        this->addr="";
    }
    person(string name,string addr,int day,int month,int year):birth_date(day,month,year)
    {
        this->name=name;
        this->addr=addr;
    }
    string get_name()
    {
        return this->name;
    }
    void set_name(string name)
    {
        this->name=name;
    }
    string get_addr()
    {
        return this->addr;
    }
    void set_addr(string addr)
    {
        this->addr=addr;
    }
    date get_birth_date()
    {
        return this->birth_date;
    }
    void set_birth_date()
    {
        this->birth_date=birth_date;
    }
    void accept()
    {
        cout << "Enter Name = ";
        cin >> this->name;
        cout << "Enter Address = ";
        cin >> this->addr;
        cout << "Enter Date Of Birth = " << endl;
        birth_date.acceptDate();
    }
    void display()
    {
        cout << "NAME = " << this->name << endl;
        cout << "ADDRESS = " << this->addr << endl;
        cout << "DATE OF BIRTH = ";
        birth_date.displayDate();
    }
    
};
class employee:public person
{
private:
    int id;
    float sal;
    string dept;
    date joining;
public:
    employee()
    {
        this->id=0;
        this->sal=0;
        this->dept="";
    }
    employee(string name,string addr,int id,float sal,string dept,int day,int month,int year):joining(day,month,year)
    {
        this->id = id;
        this->sal = sal;
        this->dept = dept;
    }
    int get_id()
    {
        return this->id;
    }
    void set_id(int id)
    {
        this->id=id;
    }
    float get_sal()
    {
        return this->sal;
    }
    void set_sal(float sal)
    {
        this->sal=sal;
    }
    string get_dept()
    {
        return this->dept;
    }
    void set_dept(string dept)
    {
        this->dept=dept;
    }
    date get_joining_date()
    {
        return this->joining;
    }
    void set_joining_date()
    {
        this->joining=joining;
    }
    void accept()
    {
        cout << "Enter ID = ";
        cin >> this->id;
        cout << "Enter Salary = ";
        cin >> this->sal;
        cout << "Enter Department = ";
        cin >> this->dept;
        cout << "Enter Date Of joining = " << endl;
        joining.acceptDate();
        person::accept();
    }
    void display()
    {
        cout << "ID = " << this->id << endl;
        cout << "SALARY = " << this->sal << endl;
        cout << "DEPARTMENT = " << this->dept << endl;
        cout << "DATE OF JOINING = ";
        joining.displayDate();
        person::display();

    }       
};
int main ()
{
    employee e1;
    e1.accept();
    e1.display();
}