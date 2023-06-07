
// simple calculator using switch case
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int a, b;
    char oper;
    cout << "Enter a: " ;
    cin >> a ;
    cout << "Enter b: " ;
    cin >> b ;

    cout << "Enter the operator: " ;
    cin >> oper ;

    switch (oper)
    {
    case '+':
        cout << a+b << endl; 
        break;
    case '-':
        cout << a-b << endl; 
        break;
    case '*':
        cout << a*b << endl; 
        break;
    case '/':
        cout << a/b << endl; 
        break;
    case '%':
        cout << a%b << endl; 
        break;
    default:
    cout << "Invalid" << endl;
        break;
    }
    return 0;
}