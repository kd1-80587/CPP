/*Q1. Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
In main create array of objects of Time.
Allocate the memory for the array and the object dynamically.*/

#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int min;
    int sec;

public:
    Time() {}
    Time(int h, int m, int s)
    {
        this->hour = h;
        this->min = m;
        this->sec = s;
    }
    int getHour()
    {
        return this->hour;
    }
    void setHour(int hour)
    {
        this->hour = hour;
    }
    int getMin()
    {
        return this->min;
    }
    void setMin(int min)
    {
        this->min = min;
    }
    int getSec()
    {
        return this->sec;
    }
    void setSec(int sec)
    {
        this->sec = sec;
    }
    // void acceptTime()
    // {
    //     cout<<"Enter hour = ";
    //     cin>>hour;
    //     cout<<"Enter Min = ";
    //     cin>>min;
    //     cout<<"Enter sec = ";
    //     cin>>sec;

    // }
    void printTime()
    {
        cout << "Time = " << hour << " : " << min << " : " << sec << endl;
    }
    ~Time()
    {
    }
};
int main()
{

    Time **arr = new Time *[3];

    arr[0] = new Time(10, 10, 10);
    arr[1] = new Time(11, 10, 22);
    arr[2] = new Time(12, 8, 55);

    for (int i = 0; i < 3; i++)
    {
        cout << " index= " << i << endl;
        arr[i]->printTime();
    }
    for (int i = 0; i < 3; i++)
    {
        delete arr[i];
    }
    delete[] arr;
}