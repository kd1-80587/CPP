#include<iostream>
using namespace std;

class product
{
private:
    int id;
    string title;
    float price;
    string type;

public:
    product()
    {
        cout<<"Product Constructor"<<endl;
        this->id=0;
        this->title="";
        this->price=0;
        this->type="";
    }
    product(int id,string title,float price,string type)
    {
        this->id=id;
        this->title=title;
        this->price=price;
        this->type=type;
    }
    int get_price()
    {
        return this->price;
    }
    void set_price(float price)
    {
        this->price = price;
    }
    string get_type()
    {
        return this->type;
    }
    void set_type(string type)
    {
        this->type = type;
    }
    virtual void addProduct()
    {
        cout << "Enter the ID = ";
        cin >> this->id;
        cout << "Enter the TITLE= ";
        cin >> this->title;
        cout << "Enter the PRICE = ";
        cin >> this->price;
        cout << "Enter the TYPE = ";
        cin >> this->type;
    }
    void display()
    {
        cout<<"ID = "<<id<<endl;
        cout<<"TITLE = "<<title<<endl;
        cout<<"PRICE = "<<price<<endl;


    }

};
class book:public product
{
private:
    string author;
public:
    book()
    {
        cout<<"Book Constructor"<<endl;
        this->author="";
        set_type("B");
    
    }
    book(string author)
    {
        this->author=author;

    }
    string get_author()
    {
        return this->author;
    }
    void set_author(string author)
    {
        this->author = author;
    }
    void addProduct()
    {
        product::addProduct();
        cout << "Enter the Author = ";
        cin >> this->author;
    }
    void display()
    {
        product::display();
        cout << "Author = "<<this->author<<endl;
    }
    
};
class tape:public product
{
private:
    string artist;
public:
    tape()
    {
        cout<<"Book Constructor"<<endl;
        this->artist="";
        set_type("T");
    }
    tape(string artist)
    {
        this->artist=artist;

    }
    void addProduct()
    {
        product::addProduct();
        cout << "Enter the Author = ";
        cin >> this->artist;
    }
    void display()
    {
        product::display();
        cout << "Artist = "<<this->artist<<endl;
    }
};
void calculateBill(product **arr, int index)
{
    int c = 0, d = 0;
    for (int i = 0; i < index; i++)
    {
        if (arr[i]->get_type() == "B")
        {
            c += arr[i]->get_price() * 0.90;
        }
    }
    //cout << "Total BOOK Bill =" << c << endl;
    for (int i = 0; i < index; i++)
    {
        if (arr[i]->get_type() == "T")
        {
            d += arr[i]->get_price() * 0.95;
        }
    }
    cout << "Total TAPE Bill =" << c+ d << endl;
}
enum Menu
{
    EXIT,
    ADDBOOK,
    ADDTAPE,
    CALCULATEBILL,
    DISPLAYBILL

};
Menu menu_driven()
{
    int choice;
    cout << "-------------------" << endl;
    cout << " Exit. 0" << endl;
    cout << "ADDBOOK. 1 " << endl;
    cout << "ADDTAPE. 2 " << endl;
    cout << "CALCULATEBILL. 3 " << endl;
    cout << "DISPLAYBILL. 4 " << endl;
    cout << "Enter your choice :- ";
    cin >> choice;
    cout << "-----------------------------" << endl;
    return Menu(choice);
}
int main()
{
    product *arr[3];
    //Product *p1;
    int index = 0;
    int choice;
    while ((choice = menu_driven()) != 0)
    {
        switch (choice)
        {
        case ADDBOOK:
            if (index < 3)
            {
                arr[index] = new book();
                arr[index]->addProduct();
                index++;
            }
            else
                cout << "Array is full we cannot add Book " << endl;
            break;
        case ADDTAPE:
            if (index < 3)
            {
                arr[index] = new tape();
                arr[index]->addProduct();
                index++;
            }
            else
                cout << "Array is full we cannot add Tape " << endl;
            break;
        case CALCULATEBILL:
            calculateBill( arr,index);
            break;
        case DISPLAYBILL:
            for(int i=0;i<index;i++)
            {
                arr[i]->display();
            }
            break; 

        default:
            cout << "Entered Wrong Product !!! " << endl;
            break;
        }
    }

    cout << "Thank you Visit again!!!" << endl;

    return 0;
}