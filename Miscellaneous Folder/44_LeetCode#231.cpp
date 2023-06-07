
// power of two
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>

using namespace std ;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n ;

    if (n == 0)
    {
        cout << "true" ;
    }
    else if (n < 0)
    {
        return 0;
    }
    
    int count = 0;
    while (n!=1)
    {
        if (n%2 != 0)
        {
            count++;
        }
        n /= 2;
    }
    if (count ==0)
    {
        cout << "true" ;
    }
    else
    {
        cout << "false" ;
    }

    return 0;
}

/*
2nd method

use for loop (luv babbar method)
class Solution {
    public: bool is PowerOfTwo(int n)
    {
        for(int i = 0; i <= 30 ; i++)  // 30 due to constraint given in the ques
        {
            int ans = pow(2,i) ;
            if (ans == 0)
            {
                return true;
            }
        }
        return false;
    }
}
*/