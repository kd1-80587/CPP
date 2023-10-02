#include "./cylinder.h"

cylinder::cylinder()
{
    this->radius =0;
    this->height=0;
}

cylinder::cylinder(double radius,double height)
{
    this->radius=radius;
    this->height=height;
}

void cylinder::set_height()
{
    double height;
    cout<<"enter height"<<endl;
    cin>>height;
    this->height=height;
    
}

void cylinder::set_radius()
{
    double height;
    cout<<"enter radius "<<endl;
    cin>>radius;
    this->radius=radius;
}

void cylinder::print_volume()
{
     double volume ;
    volume = 3.14*this->radius*this->radius*this->height;
    
    cout<<" volume of cylinder is "<< volume<<endl;
}



void  cylinder::get_height()
{
    cout<<"height = "<<this->height<<endl;
}
void cylinder::get_radius()
{
    cout<<"radius= "<<this->radius<<endl;
}