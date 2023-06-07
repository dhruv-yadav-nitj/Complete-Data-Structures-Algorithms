// boolean

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int a = 2 , b = 3;
    bool first = (a == b) ;
    cout << first << endl ;

    bool second = (a>b) ;
    cout << second << endl ;

    bool third = (a<b) ;
    cout << third << endl ;

    bool fourth = (a >= b) ;
    cout << fourth << endl ;

    bool fifth = (a!=b) ;
    cout << fifth << endl ;

    return 0;
}