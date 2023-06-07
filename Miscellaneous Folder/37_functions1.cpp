
//  a function to determine whether a number is odd or even
#include <iostream>
#include <cstdio>
using namespace std ;

// returns 0 if odd and 1 if even
bool isEven (int num)
{
    if (num&1) // true needs not be written
    {
        return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int num ;
    cin >> num ;
    
    if (isEven(num)) // true need not be written
    {
        cout << "EVEN" << endl ;
    }
    else
    {
        cout << "ODD" << endl ;
    }
    
    return 0;
}