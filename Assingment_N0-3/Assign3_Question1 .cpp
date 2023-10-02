/*
Q1. Write a menu driven program to calculate volume of the box(length * width * height).
Provide necessary constructors.
*/

#include <iostream>
#include <string.h>
using namespace std;

class Volume
{
private:
    float length;
    float width;
    float height;

public:
    Volume()
    {
    }

    Volume(float length, float width, float height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    void setLength(float length)
    {
        this->length = length;
    }

    float getLength()
    {
        return this->length;
    }

    void setWidth(float width)
    {
        this->width = width;
    }

    float getWidth()
    {
        return this->width;
    }

    void setHeight(float height)
    {
        this->height = height;
    }

    float getHeight()
    {
        return this->height;
    }
     void setValues();
     float getVolume();
  
};

enum Options
{
    EXIT,
    INSERT,
    VOLUMECAL,
    DEFALUTVALUE
};

Options menu()
{
    cout << "************************************";
    cout << "Pls Choose The Option Below" << endl;
    cout << "0-EXIT PROGRAM" << endl;
    cout << "1-To Enter the Values  " << endl;
    cout << "2-To Get Calculated Volume " << endl;
    cout << "3-To see Default Assign Values " << endl;
    cout << "************************************";

    int a;
    cin >> a;

    return Options(a);
}

void Volume::setValues()
{
    // Volume volume;
    int length;
    int width;
    int height;
    cout << "Enter the length - " << endl;
    cin >> length;
    setLength(length);
    cout << "Enter the width - " << endl;
    cin >> width;
    setWidth(width);
    cout << "Enter the height - " << endl;
    cin >> height;
    setHeight(height);
}

float Volume::getVolume()
{
    float a;
    a= getHeight()*getLength()*getWidth();
    return a;
}

int main()
{
    Volume v;
    float a;

    Options option;
    while ((option = menu()) != EXIT)
    {
        switch (option)
        {
        case INSERT:
            v.setValues();
            break;

        case VOLUMECAL:
             a=v.getVolume();
            cout<<"THE VOLUME IS = "<<a<<endl;
            break;

        case DEFALUTVALUE:
            cout << "3-To see Default Assign Values " << endl;
            break;

        default:
            cout << "Pls Enter Vaild Option" << endl;
        }
    }
}
