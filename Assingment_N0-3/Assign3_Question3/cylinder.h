#ifndef CYLINDER_H
#define CYLINDER_H
#include<iostream>
using namespace std;
 

 
class cylinder
{
    private :
      double radius;
      double height;
      

    public:
    cylinder();
    cylinder(double radius,double height);
     void  get_radius();
     void set_radius();
       void get_height();
    void set_height();
     void print_volume();
       
   

};


#endif