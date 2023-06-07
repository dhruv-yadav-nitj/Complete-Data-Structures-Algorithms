
// palindrome Number

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>

using namespace std ;

int main(int argc, char const *argv[])
{
    int x ;
    cin >> x ;    
    int count = 0;
    int x1 = x ;
    while (x1 != 0)
    {
        x1/=10;
        if (x1 != 0)
        {
            count++ ;
        }
    }
    double newNum = 0 ;
    int rem = 0;
    int x2 = x;
    for ( ;x2 != 0; x2/=10)
    {
        rem = x2%10 ;
        newNum += rem*pow(10,count) ;
        count-- ;
    }
    if (newNum == x)
    {
        cout << "true" << endl;
    }
    else if (x<0)
    {
        cout << "false" << endl ;
    }
    else
    {
        cout << "false" << endl ;
    }
    return 0;
}