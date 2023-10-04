#include<iostream>
using namespace std;
enum account_type
{
    EXIT,
    SAVING,
    CURRENT,
    DMAT
};
class account
{
private:    
    int id;
    account_type type;
    double balance;
public:
    account()
    {
        this->id=0;
        this->balance=0;
    }
    account(int id,account_type type)
    {
        this->id=id;
        this->type=type;
    }
    void set_id(int id)
    {
        this->id=id;
    }
    int get_id()
    {
        return this->id;
    }
    double get_balance()
    {
        return this->balance;
    }
    void deposit(double amount)
    {
        this->balance=this->balance + amount;
    }
    void withdraw(double amount)
    {
        this->balance=this->balance - amount;
    }
    void set_type(account_type type)
    {
        this->type=type;
    }
    account_type get_type()
    {
        return this->type;
    }
    void accept()
    {
        int choice;
        cout <<"ENTER ACCOUNT ID = " << endl;
        cin >> id;
        cout << "Enter Account Type:" << endl;
        cout << "Press 1 for SAVING" << endl;
        cout << "Press 2 for CURRENT" << endl;
        cout << "Press 3 for DMAT" << endl;
        cin >> choice;
        this->type=account_type(choice);
        cout <<"ENTER ACCOUNT BALANCE = " << endl;
        cin >> balance;

    }
    void display()
    {
        cout<<"ACCOUNT ID = "<< id << endl;
        switch (type)
        {
        case SAVING:
            cout << "Account Type = SAVING" << endl;
            break;
        case CURRENT:
            cout << "Account Type = CURRENT" << endl;
            break;
        case DMAT:
            cout << "Account Type = DMAT" << endl;
            break;

        default:
            cout << "Wrong Choice entered" << endl;
            break;
        }
        cout<<"ACCOUNT BALANCE = "<< balance << endl;
    }   
};

class insufficient_funds
{
private:
    int acc_id;
    double curr_balance;
    double withdraw_amount;

public:
    insufficient_funds(int acc_id,double curr_balance, double withdraw_balance)
    {
        this->acc_id = acc_id;
        this->curr_balance = curr_balance;
        this->withdraw_amount = withdraw_amount;
    }
    void display()
    {
        cout<<"Error: insufficient funds"<<endl;
        cout<<"insufficient bank balance"<<curr_balance<<"cannot withdraw"<<withdraw_amount<<endl;
    }
    void displayy(string type)
    {
        cout << type << " amount cannot be equal to or less than zero." << endl;
    }
};
int menu()
{
    int choice;
    cout << "----------------------" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit Amount" << endl;
    cout << "3. Withdraw Amount" << endl;
    cout << "4. Display Account Details" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << "----------------------" << endl;
    return choice;
}
int main()
{
    int size = 5;
    account *arr[size];
    int choice, id, amount, i = 0;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (i < 5)
            {
                arr[i] = new account;
                arr[i]->accept();
                
            
                i++;
            }
            else
                cout << "Cannot create bank account." << endl;
            break;

        case 2:
            cout << "Enter Account ID = ";
            cin >> id;
            cout << "Enter deposit amount = ";
            cin >> amount;
            for (int i = 0; i < size; i++)
            {
                if (arr[i]->get_id() ==id)
                {
                    try
                    {
                        arr[i]->deposit(amount);
                    }
                    catch(insufficient_funds i)
                    {
                        i.displayy("deposit");
                    }
                    break;
                }
                else
                {
                    cout << "Wrong Account No entered..." << endl;
                    break;
                }
            }

            break;
        case 3:
            cout << "Enter Account ID = ";
            cin >> id;
            
            for (int i = 0; i < size; i++)
            {
                if (arr[i]->get_id() == id)
                {
                    cout << "Enter withdraw amount = ";
                    cin >> amount;
                    try
                    {
                
                    
                        arr[i]->withdraw(amount);
                    }
                    catch(insufficient_funds i)
                    {
                        i.display();
                        i.displayy("withdraw");
                    }
                    break;
                }
                else
                {
                    cout << "Wrong Account No entered..." << endl;
                    break;
                }
            }
            break;
        case 4:
            cout << "Enter Account ID = ";
            cin >> id;

            for (int i = 0; i < size; i++)
            {
                if (arr[i]->get_id() == id)
                {
                    arr[i]->display();
                    break;
                }
                else
                {
                    cout << "Wrong Account No entered..." << endl;
                    break;
                }
            }
            break;
        default:
            cout << "Wrong choice entered." << endl;
            break;
        }
    }
    for (int i = 0; i < i; i++)
    {
        delete arr[i];
    }

    cout << "Thank you for using our Bank." << endl;
    return 0;
}