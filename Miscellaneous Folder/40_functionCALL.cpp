
/*
There are two most popular ways to pass parameters.

Pass by Value: In this parameter passing method, values of actual parameters are copied to function’s formal parameters and the two types of parameters are stored in different memory locations. So any changes made inside functions are not reflected in actual parameters of caller.

Pass by Reference Both actual and formal parameters refer to same locations, so any changes made inside the function are actually reflected in actual parameters of caller.
*/
#include <iostream>
#include <cstdio>
using namespace std ;

void dummy1 (int n)
{
    n++;
    cout << n << endl ;    
}
void dummy2 (int *n)
{
    int t = *n ;
    t++ ;
    *n = *n + 1 ;
    cout << t << endl;
}

int main(int argc, char const *argv[])
{
    int n ;
    cin >> n ;
    cout << "Entered Value of n: " << n << endl;
    dummy1(n) ;

    cout << "Value after dummy1: " << n << endl ;
    dummy2(&n) ;
    cout << "Value after dummy2: " << n << endl ;
    return 0;
}