#include<iostream>
using namespace std;

class fact
{
private:
    int num;
    
public:
    fact()
    {
        this->num=0;
    }
    fact(int num)
    {
        this->num=num;
    }
    void accept()
    {
        cout<<"Enter the Number";
        cin>>num;
    }
    void calculateFact()
    {
        if(num<=0)
        {
            throw 2;
        
        }
        else
        {
        int result=1;
        
        for(int i=num;i>0;i--)
        {
        result=result*i;
        }
        cout<<"FACTORIAL = "<<result<<endl;
        }
    }
};
int main()
{
    fact f1;
    f1.accept();
    try
    {
        f1.calculateFact();
    }
    catch(int error)
    {
        cout<<"NUMBER ENTERED IS NEGATIVE"<<endl;
    }
    cout<<"successful execution"<<endl;
    return 0;
    
    
}