// Q3. Write a class to find volume of a Cylinder by using following members. (volume of
// Cylinder=3.14 * radius * radius *height) (write a menu driven code for it and also use modular
// approach)
// Class having following member functions:
// Cylinder()
// Cylinder(double radius, double height)
// getRadius()
// setRadius()
// getHeight()
// setHeight()
// getVolume()
// printVolume()
// Initialize members using constructor member initializer list.

#include "./menu.h"
#include "./cylinder.h"

int main()
{
    cylinder c1;
    Emenu choice;
    while((choice=menu())!=Exit)
    {
        
        switch(choice)
        {
            case accept:
               c1.set_radius();
               c1.set_height();
               cout<<"values entered successfully"<<endl;
               break;
            case volume:
                c1.print_volume();
                break;
            case display:
                 c1.get_radius();
                 c1.get_height();
                 c1.print_volume();
                 break;
            default:
               cout<<"Invalid choice entered"<<endl;
               break;
                
        }
    }

    cout<<"successfully Exited"<<endl;
}