/*
Q1. Write a menu driven program for Student management.
In main(), create Array of Objects and provide facility for accept, print, search and sort.
For student accept name, gender, rollNumber and marks of three subjects from user and print name,
rollNumber, gender and percentage.
Provide global functions void sortRecords(Studuent[] arr) and int searchRecords(Student[] arr) for
sorting and searching array.
Search function returns index of found Student, otherwise returns -1.
*/
#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string gender;
    int rollno;
    int sub1;
    int sub2;
    int sub3;
    double percent,div;
    int sum;

public:
    Student()
    {
    }

    Student(string name, string gender, int rollno, int sub1, int sub2, int sub3)
    {
        this->name = name;
        this->gender = gender;
        this->rollno = rollno;
        this->sub1 = sub1;
        this->sub2 = sub2;
        this->sub3 = sub3;
    }

    void acceptStudent()
    {
        cout << "pls enter the name" << endl;
        cin >> name;
        cout << "Pls Enter the Roll no" << endl;
        cin >> rollno;
        cout << "Pls Enter the Gender" << endl;
        cin >> gender;
        cout << "Pls Enter marks for sub1" << endl;
        cin >> sub1;
        cout << "Pls Enter marks for sub2" << endl;
        cin >> sub2;
        cout << "Pls Enter marks for sub3" << endl;
        cin >> sub3;
        sum = sub1 + sub2 + sub3;
        percent=sum/3;
    }
    void printStudent()
    {
        cout << "The name od student NAME is: " << this->name << endl;
        cout << "The name od student ROLL NO is : " << this->rollno << endl;
        cout << "The name od student GENDER is : " << this->gender << endl;
        cout << "The name od student PERCENTAGE is : " << percent<< endl;
        cout << "***************************************" << endl;
    }
    int getRollNo()
    {
        return this->rollno;
    }

    friend void searchByStRollNo(Student arr[]);
    friend void sortingByRollNo(Student arr[]);
};

void searchByStRollNo( Student *str,int l)
{
    cout<<"Pls Enter the Roll no of Student whose details you want you show"<<endl;
    int rollno;
    cin>>rollno;
    int temp=0;

    for (int i = 0; i<l; i++)
    {
        if(str[i].getRollNo()==rollno)
        {
            temp=i+1;
            break;
        }
    }

   if(temp!=0)
   {
    cout<<"The Student Details is :"<<endl;
    str[temp-1].printStudent();
   }
   else
   {
    cout<<"NO RECORD FOUND IN LIST"<<endl;
   }


}

void sortingByRollNo(Student arr[])
{
    
}



int main()
{
    cout << "Pls Enter no of student for data entry" << endl;
    int temp;
    cin >> temp;

    Student *arr = new Student[temp];
    // Student **ptr;
    // ptr=&arr;

    for (int i = 0; i < temp; i++)
    {
        arr[i].acceptStudent();
    }

    searchByStRollNo(arr,temp);


    for (int i = 0; i < temp; i++)
    {
        arr[i].printStudent();
    }

    return 0;
}