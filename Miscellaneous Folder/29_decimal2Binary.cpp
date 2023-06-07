
// convert (+ve)decimal to binary
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int num ;
    cout << "Enter a number in decimal number system: " ;
    cin >> num ;

    
    int rem = 0;
    int count = 0;
    while (num != 0)
    {
        rem = rem + (num%2)*pow(10,count) ;
        num/= 2;
        count++ ;
    }
    cout << "Binary Form: " << rem << endl;

    return 0;
}
