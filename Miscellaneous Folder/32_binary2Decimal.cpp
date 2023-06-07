
// binary to decimal
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    cout << "Enter some number in the Binary form: ";
    int num ;
    cin >> num ;
    
    int count = 0, sum = 0;
    while (num!=0)
    {
        sum += (num%10)*pow(2,count);
        num/=10;
        count++ ;
    }
    cout << sum << endl ;

    return 0;
}