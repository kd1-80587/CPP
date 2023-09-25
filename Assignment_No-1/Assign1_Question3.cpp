/*Q3. Write a menu driven program for Student in CPP language. Create a class student with data
members roll no, name and marks. Implement the following functions
void initStudent();
void printStudentOnConsole();
void acceptStudentFromConsole();*/

#include <iostream>
using namespace std;

class Student
{
private:
    int rollno;
    string name;
    float marks;

public:
    void initStudent()
    {
        this->rollno = 01;
        this->name = "Manas Kelkar";
        this->marks = 100;
    }

    void printStudentOnConsole()
    {
        cout << "Student Roll No = " << this->rollno << endl;
        cout << "Student Name = " << this->name << endl;
        cout << "Student Marks = " << this->marks << endl;
    }
    void acceptStudentFromConsole()
    {
        cout << "Enter Roll No = ";
        cin >> rollno;
        getchar();
        cout << "Enter Name = ";
        //cin >> name;
        getline(cin, name);

        cout << "Enter Marks = ";
        cin >> marks;
    }
};

int main()
{
    int option;
    Student s;

    do
    {
        cout << "***********************************************************************" << endl;
        cout << "1.Inital Student \n 2.Accept Student \n 3.Display Student \n 0.Exit" << endl;
        cout << "***********************************************************************" << endl;
        cout << "Enter Option :";
        cin >> option;
        switch (option)
        {
        case 1:

            s.initStudent();
            break;

        case 2:

            s.acceptStudentFromConsole();
            break;

        case 3:

            s.printStudentOnConsole();
            break;

        default:

            cout << "Invalid Input" << endl;
            break;
        }

    } while (option != 0);

    return 0;
}