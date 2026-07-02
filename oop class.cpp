#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a=10;
    int *ptr=&a;//Creating a pointer (ptr) of variable a

    cout<<&a<<endl;

    cout<<ptr<<endl;

    cout<<&ptr<<endl;

    cout<<*ptr<<endl;

    a=100;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    *ptr=2000;
    cout<<a<<endl;


    getch();
}
