#include <iostream>
#include<conio.h>
using namespace std;
class worker
{
public:
    string name;
    int id;
    int age;
    int salary;
    string skill;

public:
    virtual void set() = 0; // Pure virtual function
    virtual void get()
    {
        // Virtual function
    }
    void secret()
    {
        cout << "This is Secret Information" << endl; // Non virtual Function
    }
};
class programmer : public worker
{
public:
    void set()
    {
        cout << "Enter your Name: ";
        getline(cin, name);
        fflush(stdin);
        cout << "Enter your ID: ";
        cin >> id;
        cout << "Enter your Age: ";
        cin >> age;
    }
    void get()
    {
        cout << endl
             << "Your Name is: " << name << endl;
        cout << "Your ID is: " << id << endl;
        cout << "Your Age is: " << age << endl;
    }
    void secret(int sl, string sk)
    {
        salary = sl;
        sk = skill;
        cout << "Your Salary is: " << salary << endl;
        cout << "Your Skill is: " << skill << endl;
    }
};
int main()
{
    worker *w1; // Creating a base class pointer object w1
    programmer p1;
    w1 = &p1; // Putting the address of child class object p1 into base class pointer object

    w1->set(); // calling the child class set method for virtual function
    w1->get();

    w1->secret(); // calling the Base class secret method for non virtual function
    getch();
}
