#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int marks = 95;
    string result =(marks>=40)?((marks>=80)?"A+":"Pass"):"Fail";
    cout<<result;
    getch();
}

