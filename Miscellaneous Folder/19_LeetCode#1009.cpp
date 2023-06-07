
// complement of Base 10 integer
/*
this method is the most lay man approach, this question can be done using two more methods :
1. using XOR operator (found in the discussions of this question)
2. using masking (done by luv babbar)
*/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int num ;
    cout << "Enter the number: " ;
    cin >> num ;

    // part 1: decimal to binary
    int binary = 0;
    int count = 0;
    while (num != 0)
    {
        binary = binary + (num%2)*pow(10,count) ;
        num /= 2 ;
        count++ ;
    }
    cout << binary << endl;

    // part 2: find complement
    int digit, complement = 0, count2= 0;
    while (binary!=0)
    {
        digit = binary%10;
        if (digit == 1)
        {
            digit = 0;
        }
        else if (digit == 0)
        {
            digit = 1;
        }
        complement = complement + (digit)*pow(10, count2) ;
        count2++ ;
        binary /= 10;
    }
    cout << complement << endl;

    // part 3: complement (binary) to decimal
    int ans = 0 , count3 = 0;
    while (complement != 0)
    {
        ans = ans + (complement%10)*pow(2,count3) ;
        complement /= 10 ;
        count3++;
    }
    cout << ans << endl;

    return 0;
}