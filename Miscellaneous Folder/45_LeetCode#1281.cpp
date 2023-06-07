
// Subtract the Product and Sum of Digits of an Integer

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int num ;
    cin >> num ;

    int product = 1;
    int sum = 0 ;

    int newNum = num ;
    while (newNum != 0)
    {
        sum += newNum % 10 ;
        product *= (newNum%10) ;
        newNum /= 10 ;
    }    

    cout << (product - sum) << endl ;
    
    return 0;
}